import string


def get_state(alfa, index):
    data = {}
    print("PRÓXIMO")
    for i in range(len(alfa)):
        data[alfa[i]] = input("q{} - {}: ".format(index, alfa[i])).split(',')
    data['&'] = input("q{} - &: ".format(index)).split(',')
    return data


def get_data():
    data = {}
    n_state = int(input("Numero de estados: "), 10)
    final_states = input("Estados finais: ")
    alfa = input("Alfabeto separado por virgula: ").split(',')

    print("Dados separados por virgula:")
    for i in range(n_state):
        data['q' + str(i)] = get_state(alfa, i)

    return data, alfa, final_states


def get_e_values(delta, character, data):
    values = []
    for j in range(len(delta)):
        items = data['q' + str(delta[j])][character]
        if '' not in items:
            values = list(set().union(values, items))
    return values


def new_delta(E, data):
    values = []
    for j in range(len(E)):
        items = data['q' + str(E[j])]['&']
        values = list(set().union(values, items, E[j]))
    if '' in values:
        values.remove('')
    return values


def check_include(deltas, delta):
    for j in range(len(deltas)):
        if set(deltas[j]) == set(delta):
            return False
    return True


def who_use(deltas, used):
    for i in range(len(deltas)):
        for j in range(len(used)):
            if deltas[i] not in used:
                return True, deltas[i]
    return False, []


def transform(data, alfa):
    deltas = [data["q0"]["&"]]
    delta = deltas[0]
    used = [deltas[0]]
    keep_going = True
    to_show = []

    while keep_going:
        for i in range(len(alfa)):
            E = get_e_values(delta, alfa[i], data)
            newDelta = new_delta(E, data)
            to_show.append([delta, alfa[i], newDelta, ])

            if check_include(deltas, newDelta):
                deltas.append(newDelta)
        some_to_use, newDelta = who_use(deltas, used)

        if some_to_use:
            delta = newDelta
            used.append(newDelta)
        else:
            keep_going = False

    return deltas, to_show


def show_deltas(deltas):
    alfa = list(string.ascii_uppercase)
    for i in range(len(deltas)):
        print("{}: {}".format(alfa[i], deltas[i]))


def get_letter(deltas, result):
    alfa = list(string.ascii_uppercase)
    for i in range(len(deltas)):
        if set(result) == set(deltas[i]):
            return alfa[i]


def get_final_state(final_states, delta):
    alfa = list(string.ascii_uppercase)
    for i in range(len(final_states)):
        if final_states[i] in delta:
            return True
    return False


def show_results(results, deltas, final_states, data):
    alfa = list(string.ascii_uppercase)
    deltas_renamed = {}

    for i in range(len(deltas)):
        deltas_renamed[alfa[i]] = deltas[i]

    for i in range(len(deltas)):
        for j in range(len(results)):
            if set(deltas_renamed[alfa[i]]) == set(results[j][0]):
                print("{}{} ---{}--> {}"
                      .format('-> ' if set(data['q0']['&']) == set(deltas_renamed[alfa[i]]) else ' ',
                              alfa[i],
                              results[j][1],
                              get_letter(deltas, results[j][2])),
                      '*' if get_final_state(final_states, deltas_renamed[alfa[i]]) else '')


def start():
    data, alfa, final_states = get_data()
    deltas, results = transform(data, alfa)
    show_deltas(deltas)
    show_results(results, deltas, final_states, data)


start()
