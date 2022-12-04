import pandas as pd
from faker import Faker
import random
fake = Faker()

data_size = 10000
shell_list = ['sh', 'bash', 'ksh', 'csh', 'tcsh', 'zsh', 'fish', 'oil', 'ion', 'dash', 'eshell', 'rc', 'scsh', 'xonsh', 'oh', 'elvish']


class Account:
    def __init__(self):
        self.id = random.randrange(0, 9999)
        self.name = fake.name()
        self.login = self.name.lower().replace(' ', '_') + '_' + str(self.id)
        self.shell = '/bin/' + shell_list[random.randrange(0, len(shell_list))]
        self.home_directory = '/home/' + random.choices((self.login, 'root'), weights=[0.8, 0.2])[0]
        self.person = [self.id, self.login, self.name, self.shell, self.home_directory]


def main():
    p_list = []
    for i in range(data_size):
        p_list.append(Account().person)
    data = pd.DataFrame(p_list, columns=['Идентификатор', 'Логин', 'Имя', 'Оболочка', 'Домашняя директория'])
    data.to_csv('data.csv', index=False)
    return 0


if __name__ == '__main__':
    main()
