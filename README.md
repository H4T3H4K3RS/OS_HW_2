# Овчинников Всеволод БПИ219

## Сценарий:

В гостинице 30 номеров, и несколько клиентов могут снять номер на один или несколько дней. Если все номера заняты,
клиенты ждут на скамейках, пока не освободится номер. Каждый клиент будет смоделирован как отдельный процесс в
симуляции. Руководству отеля необходимо обеспечить, чтобы клиенты могли снять номер, когда он свободен, а ожидающие
клиенты получили номер как можно быстрее.

## Решение:

Мы будем использовать семафоры POSIX для синхронизации клиентских процессов и управления доступом к общей памяти. В
общей памяти будет храниться текущий статус каждой комнаты (занята или свободна), а семафор будет гарантировать, что
только один процесс одновременно изменяет общую память. Мы также будем использовать другой семафор для отслеживания
количества свободных комнат.

Первоначально все комнаты будут свободны, и семафор свободных комнат будет установлен на 30. Каждый клиентский процесс
будет сначала проверять, есть ли свободные комнаты. Если да, он получит семафор свободной комнаты, пометит комнату как
занятую в общей памяти, освободит семафор свободной комнаты и продолжит свое пребывание. Если свободных комнат нет,
клиент будет ждать на семафоре POSIX, пока не освободится комната.

Для корректного завершения программы мы воспользуемся сигналом SIGINT (Ctrl-C). При получении этого сигнала главный
процесс установит флаг, который уведомит все клиентские процессы о необходимости изящного завершения. Перед выходом
главный процесс удалит семафоры и общую память, используя соответствующие функции.


# На 4 балла (в папке `4`)

## Вывод:

```
Number of clients: 100
[Client #0] Waiting for allocation
[Client #0]{2s} Allocated into number 0
[Client #2] Waiting for allocation
[Client #2]{2s} Allocated into number 1
[Client #1] Waiting for allocation
[Client #1]{2s} Allocated into number 2
[Client #3] Waiting for allocation
[Client #3]{2s} Allocated into number 3
[Client #4] Waiting for allocation
[Client #4]{2s} Allocated into number 4
[Client #5] Waiting for allocation
[Client #5]{2s} Allocated into number 5
[Client #6] Waiting for allocation
[Client #6]{2s} Allocated into number 6
[Client #7] Waiting for allocation
[Client #7]{2s} Allocated into number 7
[Client #8] Waiting for allocation
[Client #8]{2s} Allocated into number 8
[Client #9] Waiting for allocation
[Client #9]{2s} Allocated into number 9
[Client #10] Waiting for allocation
[Client #10]{2s} Allocated into number 10
[Client #11] Waiting for allocation
[Client #11]{2s} Allocated into number 11
[Client #12] Waiting for allocation
[Client #12]{2s} Allocated into number 12
[Client #13] Waiting for allocation
[Client #13]{2s} Allocated into number 13
[Client #14] Waiting for allocation
[Client #14]{2s} Allocated into number 14
[Client #15] Waiting for allocation
[Client #15]{2s} Allocated into number 15
[Client #16] Waiting for allocation
[Client #16]{2s} Allocated into number 16
[Client #17] Waiting for allocation
[Client #17]{2s} Allocated into number 17
[Client #18] Waiting for allocation
[Client #18]{2s} Allocated into number 18
[Client #19] Waiting for allocation
[Client #19]{2s} Allocated into number 19
[Client #20] Waiting for allocation
[Client #20]{2s} Allocated into number 20
[Client #21] Waiting for allocation
[Client #21]{2s} Allocated into number 21
[Client #22] Waiting for allocation
[Client #22]{2s} Allocated into number 22
[Client #23] Waiting for allocation
[Client #23]{2s} Allocated into number 23
[Client #24] Waiting for allocation
[Client #24]{2s} Allocated into number 24
[Client #25] Waiting for allocation
[Client #25]{2s} Allocated into number 25
[Client #26] Waiting for allocation
[Client #26]{2s} Allocated into number 26
[Client #27] Waiting for allocation
[Client #27]{2s} Allocated into number 27
[Client #28] Waiting for allocation
[Client #28]{2s} Allocated into number 28
[Client #29] Waiting for allocation
[Client #29]{2s} Allocated into number 29
[Client #30] Waiting for allocation
[Client #30]{2s} Waiting for vacant room
[Client #31] Waiting for allocation
[Client #31]{2s} Waiting for vacant room
[Client #32] Waiting for allocation
[Client #32]{2s} Waiting for vacant room
[Client #33] Waiting for allocation
[Client #33]{2s} Waiting for vacant room
[Client #34] Waiting for allocation
[Client #34]{2s} Waiting for vacant room
[Client #35] Waiting for allocation
[Client #35]{2s} Waiting for vacant room
[Client #36] Waiting for allocation
[Client #36]{2s} Waiting for vacant room
[Client #37] Waiting for allocation
[Client #37]{2s} Waiting for vacant room
[Client #38] Waiting for allocation
[Client #38]{2s} Waiting for vacant room
[Client #39] Waiting for allocation
[Client #39]{2s} Waiting for vacant room
[Client #40] Waiting for allocation
[Client #40]{2s} Waiting for vacant room
[Client #41] Waiting for allocation
[Client #41]{2s} Waiting for vacant room
[Client #42] Waiting for allocation
[Client #42]{2s} Waiting for vacant room
[Client #43] Waiting for allocation
[Client #43]{2s} Waiting for vacant room
[Client #44] Waiting for allocation
[Client #44]{2s} Waiting for vacant room
[Client #45] Waiting for allocation
[Client #45]{2s} Waiting for vacant room
[Client #46] Waiting for allocation
[Client #46]{2s} Waiting for vacant room
[Client #47] Waiting for allocation
[Client #47]{2s} Waiting for vacant room
[Client #48] Waiting for allocation
[Client #48]{2s} Waiting for vacant room
[Client #49] Waiting for allocation
[Client #49]{2s} Waiting for vacant room
[Client #50] Waiting for allocation
[Client #50]{2s} Waiting for vacant room
[Client #51] Waiting for allocation
[Client #51]{2s} Waiting for vacant room
[Client #52] Waiting for allocation
[Client #52]{2s} Waiting for vacant room
[Client #53] Waiting for allocation
[Client #53]{2s} Waiting for vacant room
[Client #54] Waiting for allocation
[Client #54]{2s} Waiting for vacant room
[Client #55] Waiting for allocation
[Client #55]{2s} Waiting for vacant room
[Client #56] Waiting for allocation
[Client #56]{2s} Waiting for vacant room
[Client #57] Waiting for allocation
[Client #57]{2s} Waiting for vacant room
[Client #58] Waiting for allocation
[Client #58]{2s} Waiting for vacant room
[Client #59] Waiting for allocation
[Client #59]{2s} Waiting for vacant room
[Client #60] Waiting for allocation
[Client #60]{2s} Waiting for vacant room
[Client #61] Waiting for allocation
[Client #61]{2s} Waiting for vacant room
[Client #62] Waiting for allocation
[Client #62]{2s} Waiting for vacant room
[Client #63] Waiting for allocation
[Client #63]{2s} Waiting for vacant room
[Client #64] Waiting for allocation
[Client #64]{2s} Waiting for vacant room
[Client #65] Waiting for allocation
[Client #65]{2s} Waiting for vacant room
[Client #67] Waiting for allocation
[Client #67]{2s} Waiting for vacant room
[Client #66] Waiting for allocation
[Client #66]{2s} Waiting for vacant room
[Client #68] Waiting for allocation
[Client #68]{2s} Waiting for vacant room
[Client #69] Waiting for allocation
[Client #69]{2s} Waiting for vacant room
[Client #71] Waiting for allocation
[Client #71]{2s} Waiting for vacant room
[Client #70] Waiting for allocation
[Client #70]{2s} Waiting for vacant room
[Client #72] Waiting for allocation
[Client #72]{2s} Waiting for vacant room
[Client #73] Waiting for allocation
[Client #73]{2s} Waiting for vacant room
[Client #74] Waiting for allocation
[Client #74]{2s} Waiting for vacant room
[Client #75] Waiting for allocation
[Client #75]{2s} Waiting for vacant room
[Client #76] Waiting for allocation
[Client #76]{2s} Waiting for vacant room
[Client #77] Waiting for allocation
[Client #77]{2s} Waiting for vacant room
[Client #78] Waiting for allocation
[Client #78]{2s} Waiting for vacant room
[Client #79] Waiting for allocation
[Client #79]{2s} Waiting for vacant room
[Client #80] Waiting for allocation
[Client #80]{2s} Waiting for vacant room
[Client #81] Waiting for allocation
[Client #81]{2s} Waiting for vacant room
[Client #82] Waiting for allocation
[Client #82]{2s} Waiting for vacant room
[Client #83] Waiting for allocation
[Client #83]{2s} Waiting for vacant room
[Client #84] Waiting for allocation
[Client #84]{2s} Waiting for vacant room
[Client #85] Waiting for allocation
[Client #85]{2s} Waiting for vacant room
[Client #86] Waiting for allocation
[Client #86]{2s} Waiting for vacant room
[Client #87] Waiting for allocation
[Client #87]{2s} Waiting for vacant room
[Client #88] Waiting for allocation
[Client #88]{2s} Waiting for vacant room
[Client #89] Waiting for allocation
[Client #89]{2s} Waiting for vacant room
[Client #90] Waiting for allocation
[Client #90]{2s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{2s} Waiting for vacant room
[Client #92] Waiting for allocation
[Client #92]{2s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #93]{2s} Waiting for vacant room
[Client #94] Waiting for allocation
[Client #94]{2s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{2s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #96]{2s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{2s} Waiting for vacant room
[Client #98] Waiting for allocation
[Client #98]{2s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #99]{2s} Waiting for vacant room
[Client #2] Checkout. Stayed for: {2}s
[Client #0] Checkout. Stayed for: {2}s
[Client #3] Checkout. Stayed for: {2}s
[Client #5] Checkout. Stayed for: {2}s
[Client #1] Checkout. Stayed for: {2}s
[Client #4] Checkout. Stayed for: {2}s
[Client #6] Checkout. Stayed for: {2}s
[Client #7] Checkout. Stayed for: {2}s
[Client #8] Checkout. Stayed for: {2}s
[Client #11] Checkout. Stayed for: {2}s
[Client #9] Checkout. Stayed for: {2}s
[Client #10] Checkout. Stayed for: {2}s
[Client #12] Checkout. Stayed for: {2}s
[Client #14] Checkout. Stayed for: {2}s
[Client #13] Checkout. Stayed for: {2}s
[Client #16] Checkout. Stayed for: {2}s
[Client #18] Checkout. Stayed for: {2}s
[Client #15] Checkout. Stayed for: {2}s
[Client #17] Checkout. Stayed for: {2}s
[Client #19] Checkout. Stayed for: {2}s
[Client #21] Checkout. Stayed for: {2}s
[Client #20] Checkout. Stayed for: {2}s
[Client #22] Checkout. Stayed for: {2}s
[Client #24] Checkout. Stayed for: {2}s
[Client #25] Checkout. Stayed for: {2}s
[Client #23] Checkout. Stayed for: {2}s
[Client #26] Checkout. Stayed for: {2}s
[Client #29] Checkout. Stayed for: {2}s
[Client #27] Checkout. Stayed for: {2}s
[Client #28] Checkout. Stayed for: {2}s
[Client #30] Waiting for allocation
[Client #30]{2s} Allocated into number 0
[Client #32] Waiting for allocation
[Client #33] Waiting for allocation
[Client #32]{2s} Allocated into number 1
[Client #33]{2s} Allocated into number 2
[Client #31] Waiting for allocation
[Client #31]{2s} Allocated into number 3
[Client #36] Waiting for allocation
[Client #36]{2s} Allocated into number 4
[Client #34] Waiting for allocation
[Client #34]{2s} Allocated into number 5
[Client #37] Waiting for allocation
[Client #35] Waiting for allocation
[Client #37]{2s} Allocated into number 6
[Client #35]{2s} Allocated into number 7
[Client #38] Waiting for allocation
[Client #40] Waiting for allocation
[Client #38]{2s} Allocated into number 8
[Client #40]{2s} Allocated into number 9
[Client #39] Waiting for allocation
[Client #39]{2s} Allocated into number 10
[Client #41] Waiting for allocation
[Client #41]{2s} Allocated into number 11
[Client #43] Waiting for allocation
[Client #43]{2s} Allocated into number 12
[Client #42] Waiting for allocation
[Client #42]{2s} Allocated into number 13
[Client #44] Waiting for allocation
[Client #44]{2s} Allocated into number 14
[Client #49] Waiting for allocation
[Client #49]{2s} Allocated into number 15
[Client #45] Waiting for allocation
[Client #45]{2s} Allocated into number 16
[Client #46] Waiting for allocation
[Client #46]{2s} Allocated into number 17
[Client #47] Waiting for allocation
[Client #47]{2s} Allocated into number 18
[Client #48] Waiting for allocation
[Client #48]{2s} Allocated into number 19
[Client #50] Waiting for allocation
[Client #50]{2s} Allocated into number 20
[Client #51] Waiting for allocation
[Client #51]{2s} Allocated into number 21
[Client #52] Waiting for allocation
[Client #55] Waiting for allocation
[Client #52]{2s} Allocated into number 22
[Client #55]{2s} Allocated into number 23
[Client #54] Waiting for allocation
[Client #54]{2s} Allocated into number 24
[Client #53] Waiting for allocation
[Client #53]{2s} Allocated into number 25
[Client #58] Waiting for allocation
[Client #58]{2s} Allocated into number 26
[Client #56] Waiting for allocation
[Client #56]{2s} Allocated into number 27
[Client #57] Waiting for allocation
[Client #57]{2s} Allocated into number 28
[Client #60] Waiting for allocation
[Client #60]{2s} Allocated into number 29
[Client #64] Waiting for allocation
[Client #64]{2s} Waiting for vacant room
[Client #59] Waiting for allocation
[Client #59]{2s} Waiting for vacant room
[Client #61] Waiting for allocation
[Client #61]{2s} Waiting for vacant room
[Client #65] Waiting for allocation
[Client #65]{2s} Waiting for vacant room
[Client #62] Waiting for allocation
[Client #62]{2s} Waiting for vacant room
[Client #63] Waiting for allocation
[Client #63]{2s} Waiting for vacant room
[Client #67] Waiting for allocation
[Client #69] Waiting for allocation
[Client #67]{2s} Waiting for vacant room
[Client #69]{2s} Waiting for vacant room
[Client #66] Waiting for allocation
[Client #66]{2s} Waiting for vacant room
[Client #70] Waiting for allocation
[Client #70]{2s} Waiting for vacant room
[Client #68] Waiting for allocation
[Client #68]{2s} Waiting for vacant room
[Client #73] Waiting for allocation
[Client #73]{2s} Waiting for vacant room
[Client #72] Waiting for allocation
[Client #72]{2s} Waiting for vacant room
[Client #71] Waiting for allocation
[Client #71]{2s} Waiting for vacant room
[Client #74] Waiting for allocation
[Client #74]{2s} Waiting for vacant room
[Client #75] Waiting for allocation
[Client #75]{2s} Waiting for vacant room
[Client #77] Waiting for allocation
[Client #76] Waiting for allocation
[Client #77]{2s} Waiting for vacant room
[Client #76]{2s} Waiting for vacant room
[Client #78] Waiting for allocation
[Client #78]{2s} Waiting for vacant room
[Client #83] Waiting for allocation
[Client #83]{2s} Waiting for vacant room
[Client #79] Waiting for allocation
[Client #79]{2s} Waiting for vacant room
[Client #80] Waiting for allocation
[Client #80]{2s} Waiting for vacant room
[Client #82] Waiting for allocation
[Client #82]{2s} Waiting for vacant room
[Client #84] Waiting for allocation
[Client #84]{2s} Waiting for vacant room
[Client #81] Waiting for allocation
[Client #81]{2s} Waiting for vacant room
[Client #85] Waiting for allocation
[Client #88] Waiting for allocation
[Client #85]{2s} Waiting for vacant room
[Client #88]{2s} Waiting for vacant room
[Client #89] Waiting for allocation
[Client #89]{2s} Waiting for vacant room
[Client #90] Waiting for allocation
[Client #90]{2s} Waiting for vacant room
[Client #86] Waiting for allocation
[Client #86]{2s} Waiting for vacant room
[Client #87] Waiting for allocation
[Client #87]{2s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{2s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #93]{2s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{2s} Waiting for vacant room
[Client #94] Waiting for allocation
[Client #92] Waiting for allocation
[Client #94]{2s} Waiting for vacant room
[Client #92]{2s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #96]{2s} Waiting for vacant room
[Client #98] Waiting for allocation
[Client #98]{2s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{2s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #99]{2s} Waiting for vacant room
[Client #32] Checkout. Stayed for: {2}s
[Client #30] Checkout. Stayed for: {2}s
[Client #33] Checkout. Stayed for: {2}s
[Client #31] Checkout. Stayed for: {2}s
[Client #36] Checkout. Stayed for: {2}s
[Client #37] Checkout. Stayed for: {2}s
[Client #34] Checkout. Stayed for: {2}s
[Client #35] Checkout. Stayed for: {2}s
[Client #38] Checkout. Stayed for: {2}s
[Client #40] Checkout. Stayed for: {2}s
[Client #43] Checkout. Stayed for: {2}s
[Client #39] Checkout. Stayed for: {2}s
[Client #41] Checkout. Stayed for: {2}s
[Client #42] Checkout. Stayed for: {2}s
[Client #44] Checkout. Stayed for: {2}s
[Client #49] Checkout. Stayed for: {2}s
[Client #45] Checkout. Stayed for: {2}s
[Client #47] Checkout. Stayed for: {2}s
[Client #46] Checkout. Stayed for: {2}s
[Client #48] Checkout. Stayed for: {2}s
[Client #51] Checkout. Stayed for: {2}s
[Client #50] Checkout. Stayed for: {2}s
[Client #52] Checkout. Stayed for: {2}s
[Client #55] Checkout. Stayed for: {2}s
[Client #54] Checkout. Stayed for: {2}s
[Client #53] Checkout. Stayed for: {2}s
[Client #57] Checkout. Stayed for: {2}s
[Client #58] Checkout. Stayed for: {2}s
[Client #56] Checkout. Stayed for: {2}s
[Client #59] Waiting for allocation
[Client #59]{3s} Allocated into number 0
[Client #60] Checkout. Stayed for: {2}s
[Client #64] Waiting for allocation
[Client #64]{3s} Allocated into number 1
[Client #61] Waiting for allocation
[Client #61]{3s} Allocated into number 2
[Client #62] Waiting for allocation
[Client #62]{3s} Allocated into number 3
[Client #65] Waiting for allocation
[Client #65]{3s} Allocated into number 4
[Client #63] Waiting for allocation
[Client #69] Waiting for allocation
[Client #63]{3s} Allocated into number 5
[Client #69]{3s} Allocated into number 6
[Client #70] Waiting for allocation
[Client #70]{3s} Allocated into number 7
[Client #67] Waiting for allocation
[Client #66] Waiting for allocation
[Client #67]{3s} Allocated into number 8
[Client #66]{3s} Allocated into number 9
[Client #74] Waiting for allocation
[Client #74]{3s} Allocated into number 10
[Client #68] Waiting for allocation
[Client #73] Waiting for allocation
[Client #68]{3s} Allocated into number 11
[Client #73]{3s} Allocated into number 12
[Client #72] Waiting for allocation
[Client #71] Waiting for allocation
[Client #72]{3s} Allocated into number 13
[Client #71]{3s} Allocated into number 14
[Client #75] Waiting for allocation
[Client #75]{3s} Allocated into number 15
[Client #76] Waiting for allocation
[Client #76]{3s} Allocated into number 16
[Client #83] Waiting for allocation
[Client #83]{3s} Allocated into number 17
[Client #79] Waiting for allocation
[Client #79]{3s} Allocated into number 18
[Client #82] Waiting for allocation
[Client #82]{3s} Allocated into number 19
[Client #77] Waiting for allocation
[Client #78] Waiting for allocation
[Client #77]{3s} Allocated into number 20
[Client #78]{3s} Allocated into number 21
[Client #80] Waiting for allocation
[Client #80]{3s} Allocated into number 22
[Client #84] Waiting for allocation
[Client #84]{3s} Allocated into number 23
[Client #88] Waiting for allocation
[Client #88]{3s} Allocated into number 24
[Client #81] Waiting for allocation
[Client #81]{3s} Allocated into number 25
[Client #85] Waiting for allocation
[Client #85]{3s} Allocated into number 26
[Client #89] Waiting for allocation
[Client #89]{3s} Allocated into number 27
[Client #90] Waiting for allocation
[Client #90]{3s} Allocated into number 28
[Client #86] Waiting for allocation
[Client #86]{3s} Allocated into number 29
[Client #87] Waiting for allocation
[Client #87]{3s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #94] Waiting for allocation
[Client #93]{3s} Waiting for vacant room
[Client #94]{3s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #96]{3s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{3s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{3s} Waiting for vacant room
[Client #92] Waiting for allocation
[Client #92]{3s} Waiting for vacant room
[Client #98] Waiting for allocation
[Client #98]{3s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{3s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #99]{3s} Waiting for vacant room
[Client #59] Checkout. Stayed for: {3}s
[Client #64] Checkout. Stayed for: {3}s
[Client #63] Checkout. Stayed for: {3}s
[Client #70] Checkout. Stayed for: {3}s
[Client #61] Checkout. Stayed for: {3}s
[Client #62] Checkout. Stayed for: {3}s
[Client #65] Checkout. Stayed for: {3}s
[Client #66] Checkout. Stayed for: {3}s
[Client #69] Checkout. Stayed for: {3}s
[Client #68] Checkout. Stayed for: {3}s
[Client #67] Checkout. Stayed for: {3}s
[Client #74] Checkout. Stayed for: {3}s
[Client #72] Checkout. Stayed for: {3}s
[Client #73] Checkout. Stayed for: {3}s
[Client #71] Checkout. Stayed for: {3}s
[Client #80] Checkout. Stayed for: {3}s
[Client #83] Checkout. Stayed for: {3}s
[Client #77] Checkout. Stayed for: {3}s
[Client #75] Checkout. Stayed for: {3}s
[Client #82] Checkout. Stayed for: {3}s
[Client #76] Checkout. Stayed for: {3}s
[Client #78] Checkout. Stayed for: {3}s
[Client #79] Checkout. Stayed for: {3}s
[Client #84] Checkout. Stayed for: {3}s
[Client #81] Checkout. Stayed for: {3}s
[Client #88] Checkout. Stayed for: {3}s
[Client #89] Checkout. Stayed for: {3}s
[Client #85] Checkout. Stayed for: {3}s
[Client #86] Checkout. Stayed for: {3}s
[Client #90] Checkout. Stayed for: {3}s
[Client #92] Waiting for allocation
[Client #92]{3s} Allocated into number 0
[Client #94] Waiting for allocation
[Client #94]{3s} Allocated into number 1
[Client #87] Waiting for allocation
[Client #93] Waiting for allocation
[Client #87]{3s} Allocated into number 2
[Client #93]{3s} Allocated into number 3
[Client #91] Waiting for allocation
[Client #95] Waiting for allocation
[Client #91]{3s} Allocated into number 4
[Client #95]{3s} Allocated into number 5
[Client #96] Waiting for allocation
[Client #96]{3s} Allocated into number 6
[Client #98] Waiting for allocation
[Client #98]{3s} Allocated into number 7
[Client #97] Waiting for allocation
[Client #97]{3s} Allocated into number 8
[Client #99] Waiting for allocation
[Client #99]{3s} Allocated into number 9
[Client #92] Checkout. Stayed for: {3}s
[Client #94] Checkout. Stayed for: {3}s
[Client #93] Checkout. Stayed for: {3}s
[Client #87] Checkout. Stayed for: {3}s
[Client #96] Checkout. Stayed for: {3}s
[Client #91] Checkout. Stayed for: {3}s
[Client #98] Checkout. Stayed for: {3}s
[Client #95] Checkout. Stayed for: {3}s
[Client #97] Checkout. Stayed for: {3}s
[Client #99] Checkout. Stayed for: {3}s
```
# На 5 баллов (в папке `5`)

## Вывод:

```
Number of clients: 100
[Client #0] Waiting for allocation
[Client #0]{2s} Allocated into number 0
[Client #1] Waiting for allocation
[Client #1]{2s} Allocated into number 1
[Client #2] Waiting for allocation
[Client #2]{2s} Allocated into number 2
[Client #3] Waiting for allocation
[Client #3]{2s} Allocated into number 3
[Client #4] Waiting for allocation
[Client #4]{2s} Allocated into number 4
[Client #5] Waiting for allocation
[Client #5]{2s} Allocated into number 5
[Client #6] Waiting for allocation
[Client #6]{2s} Allocated into number 6
[Client #7] Waiting for allocation
[Client #7]{2s} Allocated into number 7
[Client #8] Waiting for allocation
[Client #8]{2s} Allocated into number 8
[Client #9] Waiting for allocation
[Client #9]{2s} Allocated into number 9
[Client #10] Waiting for allocation
[Client #10]{2s} Allocated into number 10
[Client #11] Waiting for allocation
[Client #11]{2s} Allocated into number 11
[Client #12] Waiting for allocation
[Client #12]{2s} Allocated into number 12
[Client #13] Waiting for allocation
[Client #13]{2s} Allocated into number 13
[Client #14] Waiting for allocation
[Client #14]{2s} Allocated into number 14
[Client #15] Waiting for allocation
[Client #15]{2s} Allocated into number 15
[Client #16] Waiting for allocation
[Client #16]{2s} Allocated into number 16
[Client #17] Waiting for allocation
[Client #17]{2s} Allocated into number 17
[Client #18] Waiting for allocation
[Client #18]{2s} Allocated into number 18
[Client #19] Waiting for allocation
[Client #19]{2s} Allocated into number 19
[Client #20] Waiting for allocation
[Client #20]{2s} Allocated into number 20
[Client #21] Waiting for allocation
[Client #21]{2s} Allocated into number 21
[Client #22] Waiting for allocation
[Client #22]{2s} Allocated into number 22
[Client #23] Waiting for allocation
[Client #23]{2s} Allocated into number 23
[Client #24] Waiting for allocation
[Client #24]{2s} Allocated into number 24
[Client #25] Waiting for allocation
[Client #25]{2s} Allocated into number 25
[Client #26] Waiting for allocation
[Client #26]{2s} Allocated into number 26
[Client #27] Waiting for allocation
[Client #27]{2s} Allocated into number 27
[Client #28] Waiting for allocation
[Client #28]{2s} Allocated into number 28
[Client #29] Waiting for allocation
[Client #29]{2s} Allocated into number 29
[Client #30] Waiting for allocation
[Client #30]{2s} Waiting for vacant room
[Client #31] Waiting for allocation
[Client #31]{2s} Waiting for vacant room
[Client #32] Waiting for allocation
[Client #32]{2s} Waiting for vacant room
[Client #33] Waiting for allocation
[Client #33]{2s} Waiting for vacant room
[Client #34] Waiting for allocation
[Client #34]{2s} Waiting for vacant room
[Client #35] Waiting for allocation
[Client #35]{2s} Waiting for vacant room
[Client #36] Waiting for allocation
[Client #36]{2s} Waiting for vacant room
[Client #37] Waiting for allocation
[Client #37]{2s} Waiting for vacant room
[Client #38] Waiting for allocation
[Client #38]{2s} Waiting for vacant room
[Client #39] Waiting for allocation
[Client #39]{2s} Waiting for vacant room
[Client #40] Waiting for allocation
[Client #40]{2s} Waiting for vacant room
[Client #41] Waiting for allocation
[Client #41]{2s} Waiting for vacant room
[Client #42] Waiting for allocation
[Client #42]{2s} Waiting for vacant room
[Client #43] Waiting for allocation
[Client #43]{2s} Waiting for vacant room
[Client #44] Waiting for allocation
[Client #44]{2s} Waiting for vacant room
[Client #45] Waiting for allocation
[Client #45]{2s} Waiting for vacant room
[Client #46] Waiting for allocation
[Client #46]{2s} Waiting for vacant room
[Client #47] Waiting for allocation
[Client #47]{2s} Waiting for vacant room
[Client #48] Waiting for allocation
[Client #48]{2s} Waiting for vacant room
[Client #49] Waiting for allocation
[Client #49]{2s} Waiting for vacant room
[Client #50] Waiting for allocation
[Client #50]{2s} Waiting for vacant room
[Client #51] Waiting for allocation
[Client #51]{2s} Waiting for vacant room
[Client #52] Waiting for allocation
[Client #52]{2s} Waiting for vacant room
[Client #53] Waiting for allocation
[Client #53]{2s} Waiting for vacant room
[Client #54] Waiting for allocation
[Client #54]{2s} Waiting for vacant room
[Client #55] Waiting for allocation
[Client #55]{2s} Waiting for vacant room
[Client #56] Waiting for allocation
[Client #56]{2s} Waiting for vacant room
[Client #57] Waiting for allocation
[Client #57]{2s} Waiting for vacant room
[Client #58] Waiting for allocation
[Client #58]{2s} Waiting for vacant room
[Client #59] Waiting for allocation
[Client #59]{2s} Waiting for vacant room
[Client #60] Waiting for allocation
[Client #60]{2s} Waiting for vacant room
[Client #61] Waiting for allocation
[Client #61]{2s} Waiting for vacant room
[Client #62] Waiting for allocation
[Client #62]{2s} Waiting for vacant room
[Client #63] Waiting for allocation
[Client #63]{2s} Waiting for vacant room
[Client #64] Waiting for allocation
[Client #64]{2s} Waiting for vacant room
[Client #65] Waiting for allocation
[Client #65]{2s} Waiting for vacant room
[Client #66] Waiting for allocation
[Client #66]{2s} Waiting for vacant room
[Client #67] Waiting for allocation
[Client #67]{2s} Waiting for vacant room
[Client #68] Waiting for allocation
[Client #68]{2s} Waiting for vacant room
[Client #69] Waiting for allocation
[Client #69]{2s} Waiting for vacant room
[Client #70] Waiting for allocation
[Client #70]{2s} Waiting for vacant room
[Client #71] Waiting for allocation
[Client #71]{2s} Waiting for vacant room
[Client #72] Waiting for allocation
[Client #72]{2s} Waiting for vacant room
[Client #73] Waiting for allocation
[Client #73]{2s} Waiting for vacant room
[Client #74] Waiting for allocation
[Client #74]{2s} Waiting for vacant room
[Client #75] Waiting for allocation
[Client #75]{2s} Waiting for vacant room
[Client #76] Waiting for allocation
[Client #76]{2s} Waiting for vacant room
[Client #77] Waiting for allocation
[Client #77]{2s} Waiting for vacant room
[Client #78] Waiting for allocation
[Client #78]{2s} Waiting for vacant room
[Client #79] Waiting for allocation
[Client #79]{2s} Waiting for vacant room
[Client #80] Waiting for allocation
[Client #80]{2s} Waiting for vacant room
[Client #81] Waiting for allocation
[Client #81]{2s} Waiting for vacant room
[Client #82] Waiting for allocation
[Client #82]{2s} Waiting for vacant room
[Client #83] Waiting for allocation
[Client #83]{2s} Waiting for vacant room
[Client #84] Waiting for allocation
[Client #84]{2s} Waiting for vacant room
[Client #85] Waiting for allocation
[Client #85]{2s} Waiting for vacant room
[Client #86] Waiting for allocation
[Client #86]{2s} Waiting for vacant room
[Client #87] Waiting for allocation
[Client #87]{2s} Waiting for vacant room
[Client #88] Waiting for allocation
[Client #88]{2s} Waiting for vacant room
[Client #89] Waiting for allocation
[Client #89]{2s} Waiting for vacant room
[Client #90] Waiting for allocation
[Client #90]{2s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{2s} Waiting for vacant room
[Client #92] Waiting for allocation
[Client #92]{2s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #93]{2s} Waiting for vacant room
[Client #94] Waiting for allocation
[Client #94]{2s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{2s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #96]{2s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{2s} Waiting for vacant room
[Client #98] Waiting for allocation
[Client #98]{2s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #99]{2s} Waiting for vacant room
[Client #0] Checkout. Stayed for: {2}s
[Client #4] Checkout. Stayed for: {2}s
[Client #1] Checkout. Stayed for: {2}s
[Client #5] Checkout. Stayed for: {2}s
[Client #2] Checkout. Stayed for: {2}s
[Client #3] Checkout. Stayed for: {2}s
[Client #6] Checkout. Stayed for: {2}s
[Client #7] Checkout. Stayed for: {2}s
[Client #10] Checkout. Stayed for: {2}s
[Client #9] Checkout. Stayed for: {2}s
[Client #8] Checkout. Stayed for: {2}s
[Client #12] Checkout. Stayed for: {2}s
[Client #11] Checkout. Stayed for: {2}s
[Client #14] Checkout. Stayed for: {2}s
[Client #15] Checkout. Stayed for: {2}s
[Client #13] Checkout. Stayed for: {2}s
[Client #16] Checkout. Stayed for: {2}s
[Client #17] Checkout. Stayed for: {2}s
[Client #20] Checkout. Stayed for: {2}s
[Client #18] Checkout. Stayed for: {2}s
[Client #21] Checkout. Stayed for: {2}s
[Client #19] Checkout. Stayed for: {2}s
[Client #22] Checkout. Stayed for: {2}s
[Client #24] Checkout. Stayed for: {2}s
[Client #23] Checkout. Stayed for: {2}s
[Client #25] Checkout. Stayed for: {2}s
[Client #26] Checkout. Stayed for: {2}s
[Client #30] Waiting for allocation
[Client #30]{2s} Allocated into number 0
[Client #27] Checkout. Stayed for: {2}s
[Client #28] Checkout. Stayed for: {2}s
[Client #32] Waiting for allocation
[Client #32]{2s} Allocated into number 1
[Client #29] Checkout. Stayed for: {2}s
[Client #31] Waiting for allocation
[Client #31]{2s} Allocated into number 2
[Client #36] Waiting for allocation
[Client #36]{2s} Allocated into number 3
[Client #33] Waiting for allocation
[Client #33]{2s} Allocated into number 4
[Client #34] Waiting for allocation
[Client #34]{2s} Allocated into number 5
[Client #39] Waiting for allocation
[Client #39]{2s} Allocated into number 6
[Client #35] Waiting for allocation
[Client #35]{2s} Allocated into number 7
[Client #37] Waiting for allocation
[Client #37]{2s} Allocated into number 8
[Client #38] Waiting for allocation
[Client #38]{2s} Allocated into number 9
[Client #40] Waiting for allocation
[Client #40]{2s} Allocated into number 10
[Client #41] Waiting for allocation
[Client #41]{2s} Allocated into number 11
[Client #43] Waiting for allocation
[Client #43]{2s} Allocated into number 12
[Client #45] Waiting for allocation
[Client #45]{2s} Allocated into number 13
[Client #42] Waiting for allocation
[Client #42]{2s} Allocated into number 14
[Client #44] Waiting for allocation
[Client #48] Waiting for allocation
[Client #44]{2s} Allocated into number 15
[Client #48]{2s} Allocated into number 16
[Client #49] Waiting for allocation
[Client #49]{2s} Allocated into number 17
[Client #47] Waiting for allocation
[Client #50] Waiting for allocation
[Client #47]{2s} Allocated into number 18
[Client #50]{2s} Allocated into number 19
[Client #46] Waiting for allocation
[Client #46]{2s} Allocated into number 20
[Client #51] Waiting for allocation
[Client #51]{2s} Allocated into number 21
[Client #56] Waiting for allocation
[Client #56]{2s} Allocated into number 22
[Client #53] Waiting for allocation
[Client #53]{2s} Allocated into number 23
[Client #52] Waiting for allocation
[Client #52]{2s} Allocated into number 24
[Client #58] Waiting for allocation
[Client #58]{2s} Allocated into number 25
[Client #59] Waiting for allocation
[Client #59]{2s} Allocated into number 26
[Client #54] Waiting for allocation
[Client #54]{2s} Allocated into number 27
[Client #55] Waiting for allocation
[Client #55]{2s} Allocated into number 28
[Client #57] Waiting for allocation
[Client #57]{2s} Allocated into number 29
[Client #60] Waiting for allocation
[Client #60]{2s} Waiting for vacant room
[Client #61] Waiting for allocation
[Client #61]{2s} Waiting for vacant room
[Client #62] Waiting for allocation
[Client #62]{2s} Waiting for vacant room
[Client #63] Waiting for allocation
[Client #65] Waiting for allocation
[Client #63]{2s} Waiting for vacant room
[Client #69] Waiting for allocation
[Client #65]{2s} Waiting for vacant room
[Client #69]{2s} Waiting for vacant room
[Client #67] Waiting for allocation
[Client #67]{2s} Waiting for vacant room
[Client #64] Waiting for allocation
[Client #64]{2s} Waiting for vacant room
[Client #66] Waiting for allocation
[Client #66]{2s} Waiting for vacant room
[Client #68] Waiting for allocation
[Client #68]{2s} Waiting for vacant room
[Client #70] Waiting for allocation
[Client #72] Waiting for allocation
[Client #70]{2s} Waiting for vacant room
[Client #72]{2s} Waiting for vacant room
[Client #71] Waiting for allocation
[Client #71]{2s} Waiting for vacant room
[Client #75] Waiting for allocation
[Client #73] Waiting for allocation
[Client #75]{2s} Waiting for vacant room
[Client #73]{2s} Waiting for vacant room
[Client #77] Waiting for allocation
[Client #77]{2s} Waiting for vacant room
[Client #74] Waiting for allocation
[Client #76] Waiting for allocation
[Client #74]{2s} Waiting for vacant room
[Client #76]{2s} Waiting for vacant room
[Client #79] Waiting for allocation
[Client #79]{2s} Waiting for vacant room
[Client #78] Waiting for allocation
[Client #78]{2s} Waiting for vacant room
[Client #82] Waiting for allocation
[Client #82]{2s} Waiting for vacant room
[Client #80] Waiting for allocation
[Client #80]{2s} Waiting for vacant room
[Client #83] Waiting for allocation
[Client #83]{2s} Waiting for vacant room
[Client #81] Waiting for allocation
[Client #81]{2s} Waiting for vacant room
[Client #85] Waiting for allocation
[Client #85]{2s} Waiting for vacant room
[Client #88] Waiting for allocation
[Client #84] Waiting for allocation
[Client #88]{2s} Waiting for vacant room
[Client #84]{2s} Waiting for vacant room
[Client #86] Waiting for allocation
[Client #86]{2s} Waiting for vacant room
[Client #87] Waiting for allocation
[Client #87]{2s} Waiting for vacant room
[Client #89] Waiting for allocation
[Client #89]{2s} Waiting for vacant room
[Client #90] Waiting for allocation
[Client #90]{2s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{2s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #93]{2s} Waiting for vacant room
[Client #92] Waiting for allocation
[Client #92]{2s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #94] Waiting for allocation
[Client #96]{2s} Waiting for vacant room
[Client #94]{2s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{2s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{2s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #98] Waiting for allocation
[Client #99]{2s} Waiting for vacant room
[Client #98]{2s} Waiting for vacant room
[Client #30] Checkout. Stayed for: {2}s
[Client #32] Checkout. Stayed for: {2}s
[Client #31] Checkout. Stayed for: {2}s
[Client #36] Checkout. Stayed for: {2}s
[Client #33] Checkout. Stayed for: {2}s
[Client #34] Checkout. Stayed for: {2}s
[Client #35] Checkout. Stayed for: {2}s
[Client #39] Checkout. Stayed for: {2}s
[Client #38] Checkout. Stayed for: {2}s
[Client #41] Checkout. Stayed for: {2}s
[Client #43] Checkout. Stayed for: {2}s
[Client #37] Checkout. Stayed for: {2}s
[Client #40] Checkout. Stayed for: {2}s
[Client #45] Checkout. Stayed for: {2}s
[Client #42] Checkout. Stayed for: {2}s
[Client #48] Checkout. Stayed for: {2}s
[Client #44] Checkout. Stayed for: {2}s
[Client #50] Checkout. Stayed for: {2}s
[Client #47] Checkout. Stayed for: {2}s
[Client #49] Checkout. Stayed for: {2}s
[Client #58] Checkout. Stayed for: {2}s
[Client #46] Checkout. Stayed for: {2}s
[Client #55] Checkout. Stayed for: {2}s
[Client #57] Checkout. Stayed for: {2}s
[Client #56] Checkout. Stayed for: {2}s
[Client #59] Checkout. Stayed for: {2}s
[Client #54] Checkout. Stayed for: {2}s
[Client #51] Checkout. Stayed for: {2}s
[Client #53] Checkout. Stayed for: {2}s
[Client #52] Checkout. Stayed for: {2}s
[Client #60] Waiting for allocation
[Client #60]{3s} Allocated into number 0
[Client #61] Waiting for allocation
[Client #62] Waiting for allocation
[Client #62]{3s} Allocated into number 1
[Client #61]{3s} Allocated into number 2
[Client #63] Waiting for allocation
[Client #63]{3s} Allocated into number 3
[Client #65] Waiting for allocation
[Client #65]{3s} Allocated into number 4
[Client #66] Waiting for allocation
[Client #67] Waiting for allocation
[Client #67]{3s} Allocated into number 5
[Client #69] Waiting for allocation
[Client #69]{3s} Allocated into number 6
[Client #66]{3s} Allocated into number 7
[Client #72] Waiting for allocation
[Client #68] Waiting for allocation
[Client #72]{3s} Allocated into number 8
[Client #68]{3s} Allocated into number 9
[Client #70] Waiting for allocation
[Client #70]{3s} Allocated into number 10
[Client #64] Waiting for allocation
[Client #64]{3s} Allocated into number 11
[Client #77] Waiting for allocation
[Client #77]{3s} Allocated into number 12
[Client #71] Waiting for allocation
[Client #71]{3s} Allocated into number 13
[Client #73] Waiting for allocation
[Client #75] Waiting for allocation
[Client #75]{3s} Allocated into number 14
[Client #73]{3s} Allocated into number 15
[Client #76] Waiting for allocation
[Client #76]{3s} Allocated into number 16
[Client #79] Waiting for allocation
[Client #79]{3s} Allocated into number 17
[Client #74] Waiting for allocation
[Client #74]{3s} Allocated into number 18
[Client #78] Waiting for allocation
[Client #78]{3s} Allocated into number 19
[Client #81] Waiting for allocation
[Client #81]{3s} Allocated into number 20
[Client #82] Waiting for allocation
[Client #82]{3s} Allocated into number 21
[Client #83] Waiting for allocation
[Client #83]{3s} Allocated into number 22
[Client #84] Waiting for allocation
[Client #84]{3s} Allocated into number 23
[Client #80] Waiting for allocation
[Client #80]{3s} Allocated into number 24
[Client #85] Waiting for allocation
[Client #85]{3s} Allocated into number 25
[Client #88] Waiting for allocation
[Client #88]{3s} Allocated into number 26
[Client #86] Waiting for allocation
[Client #89] Waiting for allocation
[Client #86]{3s} Allocated into number 27
[Client #89]{3s} Allocated into number 28
[Client #87] Waiting for allocation
[Client #87]{3s} Allocated into number 29
[Client #90] Waiting for allocation
[Client #90]{3s} Waiting for vacant room
[Client #93] Waiting for allocation
[Client #93]{3s} Waiting for vacant room
[Client #92] Waiting for allocation
[Client #92]{3s} Waiting for vacant room
[Client #91] Waiting for allocation
[Client #91]{3s} Waiting for vacant room
[Client #96] Waiting for allocation
[Client #96]{3s} Waiting for vacant room
[Client #94] Waiting for allocation
[Client #94]{3s} Waiting for vacant room
[Client #95] Waiting for allocation
[Client #95]{3s} Waiting for vacant room
[Client #97] Waiting for allocation
[Client #97]{3s} Waiting for vacant room
[Client #99] Waiting for allocation
[Client #99]{3s} Waiting for vacant room
[Client #98] Waiting for allocation
[Client #98]{3s} Waiting for vacant room
[Client #60] Checkout. Stayed for: {3}s
[Client #62] Checkout. Stayed for: {3}s
[Client #61] Checkout. Stayed for: {3}s
[Client #63] Checkout. Stayed for: {3}s
[Client #65] Checkout. Stayed for: {3}s
[Client #67] Checkout. Stayed for: {3}s
[Client #66] Checkout. Stayed for: {3}s
[Client #72] Checkout. Stayed for: {3}s
[Client #69] Checkout. Stayed for: {3}s
[Client #70] Checkout. Stayed for: {3}s
[Client #77] Checkout. Stayed for: {3}s
[Client #68] Checkout. Stayed for: {3}s
[Client #64] Checkout. Stayed for: {3}s
[Client #71] Checkout. Stayed for: {3}s
[Client #75] Checkout. Stayed for: {3}s
[Client #73] Checkout. Stayed for: {3}s
[Client #76] Checkout. Stayed for: {3}s
[Client #78] Checkout. Stayed for: {3}s
[Client #79] Checkout. Stayed for: {3}s
[Client #74] Checkout. Stayed for: {3}s
[Client #82] Checkout. Stayed for: {3}s
[Client #81] Checkout. Stayed for: {3}s
[Client #83] Checkout. Stayed for: {3}s
[Client #84] Checkout. Stayed for: {3}s
[Client #80] Checkout. Stayed for: {3}s
[Client #89] Checkout. Stayed for: {3}s
[Client #88] Checkout. Stayed for: {3}s
[Client #86] Checkout. Stayed for: {3}s
[Client #85] Checkout. Stayed for: {3}s
[Client #87] Checkout. Stayed for: {3}s
[Client #90] Waiting for allocation
[Client #90]{3s} Allocated into number 0
[Client #93] Waiting for allocation
[Client #93]{3s} Allocated into number 1
[Client #92] Waiting for allocation
[Client #92]{3s} Allocated into number 2
[Client #91] Waiting for allocation
[Client #91]{3s} Allocated into number 3
[Client #94] Waiting for allocation
[Client #94]{3s} Allocated into number 4
[Client #97] Waiting for allocation
[Client #97]{3s} Allocated into number 5
[Client #98] Waiting for allocation
[Client #98]{3s} Allocated into number 6
[Client #96] Waiting for allocation
[Client #96]{3s} Allocated into number 7
[Client #95] Waiting for allocation
[Client #95]{3s} Allocated into number 8
[Client #99] Waiting for allocation
[Client #99]{3s} Allocated into number 9
[Client #90] Checkout. Stayed for: {3}s
[Client #97] Checkout. Stayed for: {3}s
[Client #98] Checkout. Stayed for: {3}s
[Client #96] Checkout. Stayed for: {3}s
[Client #95] Checkout. Stayed for: {3}s
[Client #99] Checkout. Stayed for: {3}s
[Client #93] Checkout. Stayed for: {3}s
[Client #92] Checkout. Stayed for: {3}s
[Client #91] Checkout. Stayed for: {3}s
[Client #94] Checkout. Stayed for: {3}s
```

# На 6 баллов (в папке `6`)

## Вывод:

```
Number of clients: 100
[Client #0] Waiting for allocation
[Client #0]{2s} Allocated into number 0
[Client #1] Waiting for allocation
[Client #1]{2s} Allocated into number 1
[Client #2] Waiting for allocation
[Client #2]{2s} Allocated into number 2
[Client #3] Waiting for allocation
[Client #3]{2s} Allocated into number 3
[Client #4] Waiting for allocation
[Client #4]{2s} Allocated into number 4
[Client #5] Waiting for allocation
[Client #5]{2s} Allocated into number 5
[Client #6] Waiting for allocation
[Client #6]{2s} Allocated into number 6
[Client #7] Waiting for allocation
[Client #7]{2s} Allocated into number 7
[Client #8] Waiting for allocation
[Client #8]{2s} Allocated into number 8
[Client #9] Waiting for allocation
[Client #9]{2s} Allocated into number 9
[Client #10] Waiting for allocation
[Client #10]{2s} Allocated into number 10
[Client #11] Waiting for allocation
[Client #11]{2s} Allocated into number 11
[Client #12] Waiting for allocation
[Client #12]{2s} Allocated into number 12
[Client #13] Waiting for allocation
[Client #13]{2s} Allocated into number 13
[Client #14] Waiting for allocation
[Client #14]{2s} Allocated into number 14
[Client #15] Waiting for allocation
[Client #15]{2s} Allocated into number 15
[Client #16] Waiting for allocation
[Client #16]{2s} Allocated into number 16
[Client #17] Waiting for allocation
[Client #17]{2s} Allocated into number 17
[Client #18] Waiting for allocation
[Client #18]{2s} Allocated into number 18
[Client #19] Waiting for allocation
[Client #19]{2s} Allocated into number 19
[Client #20] Waiting for allocation
[Client #20]{2s} Allocated into number 20
[Client #21] Waiting for allocation
[Client #21]{2s} Allocated into number 21
[Client #22] Waiting for allocation
[Client #22]{2s} Allocated into number 22
[Client #23] Waiting for allocation
[Client #23]{2s} Allocated into number 23
[Client #24] Waiting for allocation
[Client #24]{2s} Allocated into number 24
[Client #25] Waiting for allocation
[Client #25]{2s} Allocated into number 25
[Client #26] Waiting for allocation
[Client #26]{2s} Allocated into number 26
[Client #27] Waiting for allocation
[Client #27]{2s} Allocated into number 27
[Client #28] Waiting for allocation
[Client #28]{2s} Allocated into number 28
[Client #29] Waiting for allocation
[Client #29]{2s} Allocated into number 29
[Client #30] Waiting for allocation
[Client #31] Waiting for allocation
[Client #32] Waiting for allocation
[Client #33] Waiting for allocation
[Client #34] Waiting for allocation
[Client #35] Waiting for allocation
[Client #36] Waiting for allocation
[Client #37] Waiting for allocation
[Client #38] Waiting for allocation
[Client #39] Waiting for allocation
[Client #40] Waiting for allocation
[Client #41] Waiting for allocation
[Client #43] Waiting for allocation
[Client #44] Waiting for allocation
[Client #42] Waiting for allocation
[Client #45] Waiting for allocation
[Client #46] Waiting for allocation
[Client #47] Waiting for allocation
[Client #48] Waiting for allocation
[Client #49] Waiting for allocation
[Client #50] Waiting for allocation
[Client #51] Waiting for allocation
[Client #52] Waiting for allocation
[Client #54] Waiting for allocation
[Client #53] Waiting for allocation
[Client #55] Waiting for allocation
[Client #56] Waiting for allocation
[Client #57] Waiting for allocation
[Client #58] Waiting for allocation
[Client #59] Waiting for allocation
[Client #60] Waiting for allocation
[Client #61] Waiting for allocation
[Client #62] Waiting for allocation
[Client #63] Waiting for allocation
[Client #64] Waiting for allocation
[Client #65] Waiting for allocation
[Client #66] Waiting for allocation
[Client #67] Waiting for allocation
[Client #68] Waiting for allocation
[Client #69] Waiting for allocation
[Client #70] Waiting for allocation
[Client #71] Waiting for allocation
[Client #72] Waiting for allocation
[Client #73] Waiting for allocation
[Client #74] Waiting for allocation
[Client #75] Waiting for allocation
[Client #76] Waiting for allocation
[Client #77] Waiting for allocation
[Client #78] Waiting for allocation
[Client #79] Waiting for allocation
[Client #80] Waiting for allocation
[Client #81] Waiting for allocation
[Client #82] Waiting for allocation
[Client #83] Waiting for allocation
[Client #84] Waiting for allocation
[Client #85] Waiting for allocation
[Client #86] Waiting for allocation
[Client #87] Waiting for allocation
[Client #88] Waiting for allocation
[Client #89] Waiting for allocation
[Client #90] Waiting for allocation
[Client #91] Waiting for allocation
[Client #92] Waiting for allocation
[Client #93] Waiting for allocation
[Client #94] Waiting for allocation
[Client #95] Waiting for allocation
[Client #96] Waiting for allocation
[Client #97] Waiting for allocation
[Client #98] Waiting for allocation
[Client #99] Waiting for allocation
[Client #0] Checkout. Stayed for: {2}s
[Client #30]{2s} Allocated into number 0
[Client #1] Checkout. Stayed for: {2}s
[Client #2] Checkout. Stayed for: {2}s
[Client #3] Checkout. Stayed for: {2}s
[Client #5] Checkout. Stayed for: {2}s
[Client #4] Checkout. Stayed for: {2}s
[Client #6] Checkout. Stayed for: {2}s
[Client #7] Checkout. Stayed for: {2}s
[Client #11] Checkout. Stayed for: {2}s
[Client #9] Checkout. Stayed for: {2}s
[Client #15] Checkout. Stayed for: {2}s
[Client #8] Checkout. Stayed for: {2}s
[Client #14] Checkout. Stayed for: {2}s
[Client #12] Checkout. Stayed for: {2}s
[Client #16] Checkout. Stayed for: {2}s
[Client #10] Checkout. Stayed for: {2}s
[Client #13] Checkout. Stayed for: {2}s
[Client #17] Checkout. Stayed for: {2}s
[Client #19] Checkout. Stayed for: {2}s
[Client #21] Checkout. Stayed for: {2}s
[Client #18] Checkout. Stayed for: {2}s
[Client #20] Checkout. Stayed for: {2}s
[Client #23] Checkout. Stayed for: {2}s
[Client #28] Checkout. Stayed for: {2}s
[Client #22] Checkout. Stayed for: {2}s
[Client #29] Checkout. Stayed for: {2}s
[Client [Client #27] Checkout. Stayed for: {2}s
[Client #36]{2s} Allocated into number 5
[Client #26] Checkout. Stayed for: {2}s
[Client #31]{2s} Allocated into number 1
[Client #32]{2s} Allocated into number 2
[Client #52]{2s} Allocated into number 22
[Client #57]{2s} Allocated into number 25
[Client #33]{2s} Allocated into number 3
[Client #34]{2s} Allocated into number 4
[Client #35]{2s} Allocated into number 8
[Client #38]{2s} Allocated into number 9
[Client #37]{2s} Allocated into number 6
[Client #43]{2s} Allocated into number 10
[Client #46]{2s} Allocated into number 14
[Client #44]{2s} Allocated into number 12
[Client #41]{2s} Allocated into number 11
[Client #48]{2s} Allocated into number 15
[Client #39]{2s} Allocated into number 7
[Client #47]{2s} Allocated into number 16
[Client #40]{2s} Allocated into number 13
[Client #49]{2s} Allocated into number 18
[Client #51]{2s} Allocated into number 19
[Client #42]{2s} Allocated into number 17
[Client #50]{2s} Allocated into number 21
[Clie[Client #54]{2s} Allocated into number 23
[Client #45]{2s} Allocated into number 20
[Client #55]{2s} Allocated into number 27
[Client #58]{2s} Allocated into number 28
[Client #53]{2s} Allocated into number 26
[Client #59]{2s} Allocated into number 29
[Client #24] Checkout. Stayed for: {2}s
nt #56]{2s} Allocated into number 24
#25] Checkout. Stayed for: {2}s
[Client #30] Checkout. Stayed for: {2}s
[Client #61]{2s} Allocated into number 0
[Client #36] Checkout. Stayed for: {2}s
[Client #56] Checkout. Stayed for: {2}s
[Client #31] Checkout. Stayed for: {2}s
[Client #33] Checkout. Stayed for: {2}s
[Client #37] Checkout. Stayed for: {2}s
[Client #41] Checkout. Stayed for: {2}s
[Client #40] Checkout. Stayed for: {2}s
[Client #50] Checkout. Stayed for: {2}s
[Client #45] Checkout. Stayed for: {2}s
[Client #52] Checkout. Stayed for: {2}s
[Client #51] Checkout. Stayed for: {2}s
[Client #55] Checkout. Stayed for: {2}s
[Client #39] Checkout. Stayed for: {2}s
[Client #53] Checkout. Stayed for: {2}s
[Client #35] Checkout. Stayed for: {2}s
[Client #32] Checkout. Stayed for: {2}s
[Client #46] Checkout. Stayed for: {2}s
[Client #57] Checkout. Stayed for: {2}s
[Client #48] Checkout. Stayed for: {2}s
[Client #34] Checkout. Stayed for: {2}s
[Client #38] Checkout. Stayed for: {2}s
[Client #43] Checkout. Stayed for: {2}s
[Client #49] Checkout. Stayed for: {2}s
[Client #44] Checkout. Stayed for: {2}s
[Client #58] Checkout. Stayed for: {2}s
[Client #59] Checkout. Stayed for: {2}s
[Client #65]{2s} Allocated into number 2
[Client #71]{2s} Allocated into number 9
[Client #73]{2s} Allocated into number 12
[Client #67]{2s} Allocated into number 3
[Client #68]{2s} Allocated into number 4
[Client #70]{2s} Allocated into number 7
[Client #72]{2s} Allocated into number 8
[Client #66]{2s} Allocated into number 6
[Client #76]{2s} Allocated into number 10
[Client #79]{2s} Allocated into number 16
[Client #77]{2s} Allocated into number 14
[Client #78]{2s} Allocated into number 15
[Client #75]{2s} Allocated into number 13
[Client #74]{2s} Allocated into number 11
[Client #81]{2s} Allocated into number 17
[Client #82]{2s} Allocated into number 18
[Client #84]{2s} Allocated into number 20
[Client #80]{2s} Allocated into number 19
[Client #86]{2s} Allocated into number 22
[Client #83]{2s} Allocated into number 21
[Client #85]{2s} Allocated into number 23
[Client #87]{2s} Allocated into number 25
[Cl[Client #88]{2s} Allocated into number 27

[Client #54] Checkout. Stayed for: {2}s
ient #90]{2s} Allocated into number 26
[Client #92]{2s} Allocated into number 28
[Client #89]{2s} Allocated into number 24
[Client #91]{2s} Allocated into number 29
[Client #64]{2s} Allocated into number 1
[Client #69]{2s} Allocated into number 5
[Client #42] Checkout. Stayed for: {2}s
[Client #61] Checkout. Stayed for: {2}s
[Client #93]{2s} Allocated into number 0
[Client #90] Checkout. Stayed for: {2}s
[Client #95]{2s} Allocated into number 21
[Client #94]{2s} Allocated into number 26
[Client #83] Checkout. Stayed for: {2}s
[Client #73] Checkout. Stayed for: {2}s
[Client #65] Checkout. Stayed for: {2}s
[Client #71] Checkout. Stayed for: {2}s
[Client #67] Checkout. Stayed for: {2}s
[Client #68] Checkout. Stayed for: {2}s
[Client #70] Checkout. Stayed for: {2}s
[Client #66] Checkout. Stayed for: {2}s
[Client #72] Checkout. Stayed for: {2}s
[Client #76] Checkout. Stayed for: {2}s
[Client #79] Checkout. Stayed for: {2}s
[Client #78] Checkout. Stayed for: {2}s
[Client #77] Checkout. Stayed for: {2}s
[Client #75] Checkout. Stayed for: {2}s
[Client #74] Checkout. Stayed for: {2}s
[Client #82] Checkout. Stayed for: {2}s
[Client #81] Checkout. Stayed for: {2}s
[Client #84] Checkout. Stayed for: {2}s
[Client #80] Checkout. Stayed for: {2}s
[Client #85] Checkout. Stayed for: {2}s
[Client #86] Checkout. Stayed for: {2}s
[Client #87] Checkout. Stayed for: {2}s
[Client #88] Checkout. Stayed for: {2}s
[Client #92] Checkout. Stayed for: {2}s
[Client #91] Checkout. Stayed for: {2}s
[Client #89] Checkout. Stayed for: {2}s
[Client #69] Checkout. Stayed for: {2}s

[Client #97]{2s} Allocated into number 1
[Client #98]{2s} Allocated into number 2
[Client #63]{2s} Allocated into number 8
[Client #96]{2s} Allocated into number 3
[Client #99]{2s} Allocated into number 4
[Client #62]{2s} Allocated into number 6
[Client #60]{2s} Allocated into number 7
[Client #93] Checkout. Stayed for: {2}s
[Client #95] Checkout. Stayed for: {2}s
[Client #94] Checkout. Stayed for: {2}s
[Client #97] Checkout. Stayed for: {2}s
[Client #99] Checkout. Stayed for: {2}s
[Client #96] Checkout. Stayed for: {2}s
[Client #60] Checkout. Stayed for: {2}s
[Client #62] Checkout. Stayed for: {2}s
[Client #98] Checkout. Stayed for: {2}s
[Client #63] Checkout. Stayed for: {2}s
```

