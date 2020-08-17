# Махов Александр Олегович
# Задача 2. Активные вакансии


# метод подсчёта числа интервалов и их суммарной длительности, когда было опубликовано максимум вакансий
def count_intervals(_intervals: list, min_time: int, max_time: int) -> tuple:
	# нормализуем все времена: переводим абсолютные значения в количество секунд, прошедших с минимального времени
	intervals = []
	for curr_interval in _intervals:
		intervals.append((curr_interval[0] - min_time, curr_interval[1] - min_time))
	max_time = max_time - min_time
	min_time = 0

	# построим и заполним общий интервал времени, который будет включать в себя все прочие интервалы
	# индекс - время, значение - количество опубликованных в эту секунду вакансий
	counts = [0] * (max_time + 1)
	for curr_interval in intervals:
		for moment in range(curr_interval[0], curr_interval[1] + 1):
			counts[moment] += 1

	# сформируем список секунд, когда количество опубликованных вакансий было максимальным
	max_vacancies = counts[0]  # максимальное количество одновременно опубликованных вакансий
	moments_of_maximum = [0]  # моменты времени, когда количество вакансий было максимальным
	for moment in range(1, len(counts)):
		if counts[moment] > max_vacancies:
			# нашли новый максимум вакансий, обновляем информацию
			max_vacancies = counts[moment]
			moments_of_maximum = [moment]
		elif counts[moment] == max_vacancies:
			# ещё одна секунда, когда количество вакансий было максимальным; запоминаем
			moments_of_maximum.append(moment)

	# по очереди "набрасываем" исходные интервалы на список секунд с максимальным количеством вакансий
	# если интервал не покрывает все точки максимумов, то список точек максимума разбивается на 2 подсписка
	components_of_maximum = [moments_of_maximum.copy()]  # список компонент связности на всём множестве максимумов
	for curr_interval in intervals:
		for ind in range(0, len(components_of_maximum)):
			curr_component = components_of_maximum[ind].copy()
			# строим пересечение интервала с текущей компонентой связности
			intersection = set(range(curr_interval[0], curr_interval[1] + 1)) & set(curr_component)
			if len(intersection) < len(curr_component):
				# если интервал совсем не покрывает компоненту, разбиение множества компонент ничего не изменит
				if len(intersection) != 0:
					# если интервал не покрывает всю компоненту, её надо разбить на две новых
					components_of_maximum[ind] = [x for x in curr_component if x in intersection]
					components_of_maximum.append([x for x in curr_component if x not in intersection])
					break

	return len(components_of_maximum), len(moments_of_maximum)


def main() -> None:
	# считываем входные данные
	vacancies_count = int(input())

	if vacancies_count == 0:
		print('0 0')
		return

	intervals = []  # множество всех входных временных интервалов (в виде кортежей)
	# в процессе сразу будем запоминать минимальное и максимальное время среди всех интервалов - пригодится впоследствии
	min_time = max_time = None
	for it in range(0, vacancies_count):
		input_str = input()
		space_ind = input_str.find(' ')
		beg_time = int(input_str[0:space_ind])
		end_time = int(input_str[(space_ind + 1):])
		if min_time is None or beg_time < min_time:
			min_time = beg_time
		if max_time is None or end_time > max_time:
			max_time = end_time
		intervals.append((beg_time, end_time))

	answer = count_intervals(intervals, min_time, max_time)
	print('{0} {1}'.format(answer[0], answer[1]))


# точка входа в приложение
main()
