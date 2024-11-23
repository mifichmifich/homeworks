n = int(input('Введите число посылок: '))
if 0 <= n <= 255:
    weights = []
    for i in range(n):
        weight = int(input('Введите вес посылки: '))
        if weight < 0:
            continue
        weights.append(weight)

    weights = sorted(weights, reverse=True)
    vagon_weight = int(input('Введите грузоподъемность вагона: '))
    current_weight_vagona = 0
    counter_vagons = 0
    for weight in weights:
        x = weights.pop(0)
        current_weight_vagona += x
        x = 0
        if current_weight_vagona >= vagon_weight:
            current_weight_vagona -= vagon_weight
            counter_vagons += 1
    if current_weight_vagona != 0:
        counter_vagons += 1
    print(f'Число вагонов, необходимое для перевозки всех посылок = {counter_vagons}')
else:
    print('Количество посылок не соответствует условию задания')
