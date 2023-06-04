#include <stdio.h>

int main(void) {

	printf("Hit and Blow (3桁) 解析ツール Ver1.0 へようこそ\n");

	char opt[10][10][10];
	//int count = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {

				if (i != j && j != k && i != k) {
					//各位の値が全て異なる720通りを格納

					opt[i][j][k] = 't';
					//optの値がtならば可能性としてありえる

					//printf("%c", opt[i][j][k]);
					//count++;
				}

				else {
					opt[i][j][k] = 'f';
					//optの値がfならば可能性としてありえない
				}
			}
		}
	}

	//printf("%d", count);

	int count = 0;

	do {
		char numc[4];

		if (count > 0) {
			printf("\n");
		}

		printf("\n解析する値を入力してください：");
		scanf("%s", numc);

		if (numc[0] == 'e') {
			break;
		}

		int num[3] = { numc[0] - '0', numc[1] - '0',numc[2] - '0' };
		//文字コードを数字コードに変換
		//解析する数値はnum配列[3]にint型で格納される

		int hit, blow;
		printf("hit数を入力してください：");
		scanf("%d", &hit);

		if (hit == 3) {
			printf("Win!\n");
			break;
		}

		printf("blow数を入力してください：");
		scanf("%d", &blow);

		//long cpu_time;

		if (hit == 0 && blow == 0) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (num[0] == i || num[0] == j || num[0] == k || num[1] == i || num[1] == j || num[1] == k || num[2] == i || num[2] == j || num[2] == k) {
								
								opt[i][j][k] = 'f';
								//どの桁に1文字でも使われていたらfalse
							}
						}
					}
				}
			}
		}

		if (hit == 2 && blow == 0) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i == num[0] && j == num[1] && k == num[2]) {
								opt[i][j][k] = 'f';
								//解析値を除外
							}

							if (num[0] == i && num[1] == j) {
								continue;
							}

							else if (num[0] == i && num[2] == k) {
								continue;
							}

							else if (num[1] == j && num[2] == k) {
								continue;
							}

							else {
								opt[i][j][k] = 'f';
								//どのパターンにも当てはまらないならfalse
							}

						}
					}
				}
			}
		}

		if (hit == 1 && blow == 2) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i==num[0]&&j==num[2]&&k==num[1]) {
								continue;
							}

							if (i == num[2] && j == num[1] && k == num[0]) {
								continue;
							}

							if (i == num[1] && j == num[0] && k == num[2]) {
								continue;
							}

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}

		if (hit == 1 && blow == 1) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i == num[0] && j != num[2] && k == num[1]) {
								continue;
							}
							
							if (i == num[0] && j == num[2] && k != num[1]) {
								continue;
							}
							//iがHitの場合

							if (i == num[2] && j == num[1] && k != num[0]) {
								continue;
							}

							if (i != num[2] && j == num[1] && k == num[0]) {
								continue;
							}
							//jがHitの場合

							if (i == num[1] && j != num[0] && k == num[2]) {
								continue;
							}

							if (i != num[1] && j == num[0] && k == num[2]) {
								continue;
							}
							//kがHitの場合

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}

		if (hit == 1 && blow == 0) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i == num[0]) {
								if (j != num[1] && j != num[2] && k != num[1] && k != num[2]) {
									continue;
								}
							}

							if (j == num[1]) {
								if (i != num[0] && i != num[2] && k != num[0] && k != num[2]) {
									continue;
								}
							}

							if (k == num[2]) {
								if (i != num[0] && i != num[1] && j != num[0] && j != num[1]) {
									continue;
								}
							}

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}

		if (hit == 0 && blow == 3) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i==num[1]&&j==num[2]&&k==num[0]) {
								continue;
							}

							if (i == num[2] && j == num[0] && k == num[1]) {
								continue;
							}

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}

		if (hit == 0 && blow == 2) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i == num[1] && j == num[0] && k != num[2]) {
								continue;
							}

							if (i != num[2] && j == num[0] && k == num[1]) {
								continue;
							}

							if (i == num[1] && j != num[2] && k == num[0]) {
								continue;
							}//num[2]を使わない場合

							if (i == num[2] && j == num[0] && k != num[1]) {
								continue;
							}

							if (i != num[1] && j == num[2] && k == num[0]) {
								continue;
							}

							if (i == num[2] && j != num[1] && k == num[0]) {
								continue;
							}//num[1]を使わない場合

							if (i == num[1] && j == num[2] && k != num[0]) {
								continue;
							}

							if (i != num[0] && j == num[2] && k == num[1]) {
								continue;
							}

							if (i == num[2] && j != num[0] && k == num[1]) {
								continue;
							}//num[0]を使わない場合

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}

		if (hit == 0 && blow == 1) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (i==num[1]) {
								if (j != num[0] && j != num[2] && k != num[0] && k != num[2]) {
									continue;
								}
							}//num[1]→num[0]

							if (i == num[2]) {
								if (j != num[0] && j != num[1] && k != num[0] && k != num[1]) {
									continue;
								}
							}//num[2]→num[0]

							//100の位がHitになりうる場合

							if (j == num[0]) {
								if (i != num[1] && i != num[2] && k != num[1] && k != num[2]) {
									continue;
								}
							}//num[0]→num[1]

							if (j == num[2]) {
								if (i != num[0] && i != num[1] && k != num[0] && k != num[1]) {
									continue;
								}
							}//num[2]→num[1]

							//10の位がHitになりうる場合

							if (k == num[0]) {
								if (i != num[1] && i != num[2] && j != num[1] && j != num[2]) {
									continue;
								}
							}//num[0]→num[2]

							if (k == num[1]) {
								if (i != num[0] && i != num[2] && j != num[0] && j != num[2]) {
									continue;
								}
							}//num[1]→num[2]

							//1の位がHitになりうる場合

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}


		printf("\n以下が考えられうる数です\n\n");

		int count30 = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

					if (opt[i][j][k] == 't') {

						int output = i * 100 + j * 10 + k;
						printf("%03d ", output);
						//optの値がtであるものを全て出力

						count30++;

						if (count30 == 30) {
							printf("\n");
							count30 = 0;
						}
					}
				}
			}
		}

		//cpu_time = clock();

		//printf("CPU時間： %d\n", cpu_time);

		count++;

	} while (count < 100);
	//解析回数が100回に達したらプログラムを終了する

	system("pause");

	return 0;
}