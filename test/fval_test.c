/*	fval_test.c
 *
 * (c) 2018 Sirio Balmelli
 */

/* TODO: implement the following test cases:
 * 1.1.1.1                                     # ipv4 yes
 * 192.168.1.1                                 # ipv4 yes
 * 192.168.1                                   # ipv4 no
 * 192.168                                     # ipv4 no
 * 192.                                        # ipv4 no
 * 192                                         # ipv4 no
 * 00:11:aa:bb:cc:dd                           # mac yes
 * 00:11:aa:bb:cc                              # mac no
 * 00:11:aa:bb:                                # mac no
 * 00:                                         # mac no
 * 00                                          # mac no
 * 1                                           # int yes
 * 12                                          # int yes
 * x12134                                      # int yes
 * 0x1                                         # int yes
 * b01                                         # int yes
 * 01                                          # int yes
 * 2001:0db8:85a3:0000:0000:8a2e:0370:7334     # ipv6 yes
 * 2001:db8:85a3:0:0:8a2e:370:7334             # ipv6 yes
 * 2001:db8:85a3::8a2e:370:7334                # ipv6 yes
 * ::1                                         # ipv6 yes
 * ::                                          # ipv6 yes
 */
