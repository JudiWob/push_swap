#include "header.h"

//./pushswap  88 675 2 0 999 -08643 56 78 -456 4 -666 -4 777 -543 9 -23 99 22
//./pushswap 1 -762 3 -1 2 5 999 -1111 63  -6574  30  2222 65 -222 75645 -74334 758 963 41 18 432 564 
// ./pushswap 8829 -7652 7645 -8843 3929 -6878 7280 -2923 -12 2307 -4253 7488 4474 621 -7656 -4801 7960 1684 -4049 2803 873 -8808 219 9566 -6914 7527 3578 -262 3371 4711 5075 -2723 -4417 2141 6921 -6745 1665 8406 1961 9129 -1940 -5747 5429 -492 -1969 -2184 -9926 -9209 7432 -4551 -7595 -2302 -6013 581 7199 4096 3241 4131 1988 6981 -4740 -4707 3417 -1609 -9693 9256 -9367 2231 9372 -9543 -6830 -1472 1293 8972 -4675 -4614 1270 -433 5277 1534 2138 1027 5065 2908 -6226 176 5599 8503 -837 4448 -6207 2124 5066 -7877 5796 3173 -2504 -151 -3202 1771 
//./pushswap -2303 -2352 1574 39 1747 414 -1183 1421 -2052 -1392 -275 -1870 -1561 2844 -2455 -148 -2708 -2088 3911 -1923 1382 -1965 -146 1844 3343 3751 -1279 -2631 3682 -1083 1456 -427 3118 1403 2943 -228 -498 -1069 1462 -2172 3843 -240 192 1413 -1546 -1463 -2773 1316 1362 1065 -901 1127 2438 -530 -2665 -1657 3570 3172 -1660 -2839 372 -2122 3085 358 1224 -2270 1436 1664 -1251 -2477 -397 -1859 618 -2483 -959 3082 1491 919 2675 2640 2182 -2921 1019 -2102 3883 1933 3983 683 609 -1032 -1684 -1575 812 2961 1080 -1735 3461 -2867 -2897 -215 > lines.txt 
// ./pushswap 756 -445 203 1966 -1377 -192 3197 1842 3886 -279 3519 3567 3907 -381 -735 3230 -1466 774 -1852 3257 3068 1621 430 -1819 -1261 3602 2253 2487 719 1437 1911 -2962 -2782 -519 2539 482 627 1880 -2766 -1722 1798 -1886 -920 -263 1530 3032 316 -292 -267 2856 -1686 839 2350 431 1818 781 -2170 -1418 -857 -1173 -115 2208 -147 -1518 3259 2396 1851 -2774 -1643 1647 383 -30 -2597 2588 -1387 1400 -9 2168 3028 -560 1738 2456 55 -1640 -202 1887 -2063 220 -1889 -1116 -2535 1004 -1598 772 -1777 1271 -2958 -1176 -175 > lines.txt 
//./pushswap 388 813 3970 -1164 -1673 1375 -464 3391 -1796 466 -635 -598 2207 343 -716 931 -2054 1250 2319 -1834 3822 1130 2900 1148 3115 -2062 -684 -2627 -2674 -2233 -2174 14 449 -1939 1007 2017 504 -400 -2295 -619 2509 992 2552 -2269 -1597 1556 -1840 -207 1373 1251 -1412 922 3554 -766 -220 -1724 1656 794 1894 -1231 3974 -956 3121 2338 1698 169 348 2378 3941 -930 1310 3409 -633 704 3791 -2410 2421 2446 2954 -1719 1585 -245 1855 3521 354 1539 3139 -803 971 1246 3180 -265 557 3712 1483 3323 -870 -395 1177 1106 > lines.txt 
// ./pushswap 871 -1270 -328 417 978 -98 -1078 3513 3148 2717 658 2543 -1525 2637 -492 -1564 3614 947 -605 3243 1373 -2799 3528 2435 -898 -53 -2337 3755 1716 1088 -2494 -1462 713 3839 3714 3975 3697 -1650 3138 3495 -2093 -554 -1345 2500 -1170 387 3830 -1385 1079 3114 3100 2996 1051 -66 -1645 3494 813 2672 1970 -1403 -177 -619 211 -1298 909 -283 542 2850 2874 491 1905 2799 2572 1039 -1122 3886 3443 -2807 2396 -1458 3660 2104 -2977 1260 859 -1994 -2774 1926 -2149 2318 -519 -203 -371 -22 800 -1091 -2865 52 -319 32 > lines.txt 

int main(int argc, char **argv)
{	
	stack *head_a;
	argv = split_input(&argc, argv); //evtl split oder no arguments
	head_a = createstack(argc, argv);
	indexing(head_a, argc);
	sort(&head_a, (argc - 1));
	free_list (&head_a);
	return 0;
}


