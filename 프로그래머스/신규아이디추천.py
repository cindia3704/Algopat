# 작성자: 김지수
# 작성일: 2021/01/30
# 프로그래머스 --1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
# 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
# 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
# 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
# 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
# 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
# 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
# 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

def solution(new_id):
    answer = ''
    answer = level1(new_id)
    answer = level2(answer)
    answer = level3(answer)
    answer = level4(answer)
    answer = level5(answer)
    answer = level6(answer)
    answer = level7(answer)
    return answer


def level1(new_id):
    return new_id.lower()


def level2(new_id):
    valid = '-', '_', '.'
    for i in new_id:
        if (i not in valid) and (not i.isalpha()) and (not i.isnumeric()):
            new_id = new_id.replace(i, "")
        else:
            continue
    return new_id


def level3(new_id):
    double = '..'
    while double in new_id:
        new_id = new_id.replace(double, '.')
    return new_id


def level4(new_id):
    if new_id[0] == '.' and len(new_id) > 1:
        new_id = new_id[1:]
    if new_id[-1] == '.' and len(new_id) > 1:
        new_id = new_id[0:-1]
    if len(new_id) == 1 and new_id[0] == '.':
        new_id = ""
    return new_id


def level5(new_id):
    if new_id == "":
        return "a"
    else:
        return new_id


def level6(new_id):
    print(len(new_id))
    if(len(new_id) > 15):
        new_id = new_id[0:15]
        return level4(new_id)
    else:
        return new_id


def level7(new_id):
    while(len(new_id) < 3):
        new_id = new_id+str(new_id[-1])
    return new_id
