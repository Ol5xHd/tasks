# Махов Александр Олегович
# Задача 2. Активные вакансии


# метод производит подсчёт количества интервалов, когда число вакансий было максимальным,
# а также суммарную длительность всех этих интервалов
def count_intervals(intervals: list) -> tuple:
	# по списку интервалов построим словарь, где ключом будет момент времени,
	# а значением - список интервалов, покрывающих этот момент
	# каждый интервал обозначается через индекс этого интервала в списке всех интервалов
	vacancies_by_moments = {}
	for interval_ind in range(0, len(intervals)):
		curr_interval = intervals[interval_ind]
		for moment in range(curr_interval[0], curr_interval[1] + 1):
			if moment in vacancies_by_moments:
				vacancies_by_moments[moment].append(interval_ind)
			else:
				vacancies_by_moments[moment] = [interval_ind]

	# найдём максимальное количество одновременно опубликованных вакансий
	# и список моментов времени, когда это число достигалось
	max_vacancies = 0
	moments_of_max = []
	for moment, covering_intervals in vacancies_by_moments.items():
		if len(covering_intervals) > max_vacancies:
			max_vacancies = len(covering_intervals)
			moments_of_max = [moment]
		elif len(covering_intervals) == max_vacancies:
			moments_of_max.append(moment)
	moments_of_max.sort()

	# подсчитаем количество интервалов, образующих множество моментов максимума
	intervals_of_maximum = 1
	for moment_ind in range(1, len(moments_of_max)):
		prev_moment = moments_of_max[moment_ind - 1]
		curr_moment = moments_of_max[moment_ind]
		if vacancies_by_moments[prev_moment] != vacancies_by_moments[curr_moment]:
			# в предыдущий момент времени максимум был образован другим набором интервалов, значит произошёл разрыв
			intervals_of_maximum += 1

	return intervals_of_maximum, len(moments_of_max)


def main() -> None:
	try:
		vacancies_count = int(input())  # количетсво опубликованных вакансий
		if vacancies_count == 0:
			print('0 0')
			return
		intervals = []  # множество всех входных временных интервалов (в виде кортежей)
		for it in range(0, vacancies_count):
			input_str = input()
			space_ind = input_str.find(' ')
			beg_time = int(input_str[0:space_ind])
			end_time = int(input_str[(space_ind + 1):])
			intervals.append((beg_time, end_time))
		answer = count_intervals(intervals)  # основнйо метод прграммы
		print('{0} {1}'.format(answer[0], answer[1]))  # печать результата
	except:
		print('0 0')


# точка входа в приложение
main()
