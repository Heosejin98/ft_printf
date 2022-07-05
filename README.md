# ft_printf
# 목표
### printf의 일부 기능 구현 

### prinft format 형식 태그

<aside>
📖 ** # [flag] [width] [.precision(정밀도)] [length] 서식 문자(specifier)**

</aside>

이 과제에서 서식문자 c, s, p, d, i, u, x, X, %를 구현
길이(length) 구현 할 필요 없음

| d | int값을 부호있는 10진수로 출력 |
| --- | --- |
| i | int값을 부호있는 10진수로 출력 |
| u | int값을 부호없는 10진수로 출력 |
| c | int 형으로 들어온 문자 출력 |
| s | 문자열 출력 |
| p | 포인터값을 16진수로 출력 |
| x | int값을 부호없는 16진수로 출력 10 ~ 15은 'a' ~ 'f'로 표시 |
| X | int값을 부호없는 16진수로 출력 10 ~ 15은 'A' ~ 'F'로 표시 |
| % | %출력 |

## specifier 별 flag

|  | ‘-’ | ‘0’ | ‘#’ | ‘ ’ | ‘+’ |
| --- | --- | --- | --- | --- | --- |
| c | O | O | 사용안함 | 사용안함 | 사용안함 |
| s | O | 사용안함 | 사용안함 | 사용안함 | 사용안함 |
| p | O | 사용안함 | 사용안함 | 사용안함 | 사용안함 |
| d | O | O | 사용안함 | O | O |
| i | O | O | 사용안함 | O | O |
| u | O | O | 사용안함 | 사용안함 | 사용안함 |
| x | O | O | O | 사용안함 | 사용안함 |
| X | O | O | O | 사용안함 | 사용안함 |
| % | O | O | 사용안함 | 사용안함 | 사용안함 |

# Flow Chart

![image](https://user-images.githubusercontent.com/61305083/175952126-3b422a19-94c2-4fd0-a507-d369205b61a1.png)

# 정리
---
https://velog.io/@sejin3319/42Seoul-getnextline
