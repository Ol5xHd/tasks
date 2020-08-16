# Махов Александр Олегович
# Задача 1. Преобразования слов


# метод конструирования словаря по строке, где ключ - это буква,
# а значение по ключу - список всех индексов, где эта буква находится в строке
def string_to_dict(string: str) -> dict:
	result = {}
	for ind in range(0, len(string)):
		if string[ind] in result:
			result[string[ind]].append(ind)
		else:
			result[string[ind]] = [ind]
	return result


# метод проверки, преобразуется ли исходная строка к целевой
def check_convertible(original_str: str, target_str: str) -> bool:
	# строки разной длины точно не приводятся друг к другу, не будем тратить время
	if len(original_str) != len(target_str):
		return False

	# одинаковые строки не надо преобразовывать
	if original_str == target_str:
		return True

	# преобразуем строки в словари и проверим возможность преобразования для словарей
	original_dict = string_to_dict(original_str)
	target_dict = string_to_dict(target_str)

	# в целевой строке задествованы все 33 буквы русского алфавита
	# любое преобразование исходной строки приведёт к потере какой-либо буквы
	if len(target_dict) == 33:
		return False

	# основной цикл сравнения словарей
	# будем искать соответствующие друг другу в разных словарях группы и удалять их
	while bool(target_dict):  # пока целевой словарь не пустой
		target_first_letter = next(iter(target_dict))  # берём первый попавшийся ключ в целевом словаре
		target_group = target_dict[target_first_letter]  # находим соответствующую группу индексов целевой строки
		some_index = target_group[0]  # берём первый попавшийся индекс из этой группы
		original_letter = original_str[some_index]  # в исходной строке по индексу ищем соответствующую букву
		orig_corresponding_group = original_dict[original_letter]  # по букве находим группу в исходном словаре
		# определили две группы индексов: target_group - из целевого словаря и orig_corresponding_group - из исходного
		# важно - они уже упорядочены по построению; попытаемся сравнить эти группы
		if target_group == orig_corresponding_group:
			# группы совпадают - их можно удалить из обоих словарей
			del target_dict[target_first_letter]
			del original_dict[original_letter]
		else:
			# группы не совпадают; определим общие индексы
			common_indexes = list(set(target_group) & set(orig_corresponding_group))
			# рассмторим два варианта:
			if len(orig_corresponding_group) == len(common_indexes):
				# все индексы из исходной группы нашлись в целевой, т.е. целевая включает в себя исходную
				del original_dict[original_letter]  # удаляем группу из исходного словаря
				# из целевой группы убираем все найденные символы
				target_dict[target_first_letter] = [ind for ind in target_group if ind not in common_indexes]
				# две разных буквы исходной строки могут стать одной и той же буквой в целевой строке
			elif len(orig_corresponding_group) > len(common_indexes):
				# исходная группа больше целевой, т.е. рассматриваемая буква исходной строки
				# должна стать в целевой двумя разными буквами, что невозможно
				break

	# если хоть один из словарей не пуст, то преобразование не удалось
	if bool(original_dict) or bool(target_dict):
		return False
	else:
		return True


def main() -> None:
	# считаем входные данные
	input_str = input()
	space_ind = input_str.find(' ')
	original = input_str[0:space_ind]
	target = input_str[(space_ind + 1):]

	# проверяем возможность перевода исходной строки в целевую
	convertible = check_convertible(original, target)

	# выводим результат
	if convertible:
		print(1)
	else:
		print(0)


# точка входа в приложение
main()
