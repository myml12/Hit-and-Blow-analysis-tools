#include <stdio.h>

int main(void) {

	printf("Hit and Blow (3��) ��̓c�[�� Ver1.0 �ւ悤����\n");

	char opt[10][10][10];
	//int count = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {

				if (i != j && j != k && i != k) {
					//�e�ʂ̒l���S�ĈقȂ�720�ʂ���i�[

					opt[i][j][k] = 't';
					//opt�̒l��t�Ȃ�Ή\���Ƃ��Ă��肦��

					//printf("%c", opt[i][j][k]);
					//count++;
				}

				else {
					opt[i][j][k] = 'f';
					//opt�̒l��f�Ȃ�Ή\���Ƃ��Ă��肦�Ȃ�
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

		printf("\n��͂���l����͂��Ă��������F");
		scanf("%s", numc);

		if (numc[0] == 'e') {
			break;
		}

		int num[3] = { numc[0] - '0', numc[1] - '0',numc[2] - '0' };
		//�����R�[�h�𐔎��R�[�h�ɕϊ�
		//��͂��鐔�l��num�z��[3]��int�^�Ŋi�[�����

		int hit, blow;
		printf("hit������͂��Ă��������F");
		scanf("%d", &hit);

		if (hit == 3) {
			printf("Win!\n");
			break;
		}

		printf("blow������͂��Ă��������F");
		scanf("%d", &blow);

		//long cpu_time;

		if (hit == 0 && blow == 0) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						if (i != j && j != k && i != k) {

							if (num[0] == i || num[0] == j || num[0] == k || num[1] == i || num[1] == j || num[1] == k || num[2] == i || num[2] == j || num[2] == k) {
								
								opt[i][j][k] = 'f';
								//�ǂ̌���1�����ł��g���Ă�����false
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
								//��͒l�����O
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
								//�ǂ̃p�^�[���ɂ����Ă͂܂�Ȃ��Ȃ�false
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
							//i��Hit�̏ꍇ

							if (i == num[2] && j == num[1] && k != num[0]) {
								continue;
							}

							if (i != num[2] && j == num[1] && k == num[0]) {
								continue;
							}
							//j��Hit�̏ꍇ

							if (i == num[1] && j != num[0] && k == num[2]) {
								continue;
							}

							if (i != num[1] && j == num[0] && k == num[2]) {
								continue;
							}
							//k��Hit�̏ꍇ

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
							}//num[2]���g��Ȃ��ꍇ

							if (i == num[2] && j == num[0] && k != num[1]) {
								continue;
							}

							if (i != num[1] && j == num[2] && k == num[0]) {
								continue;
							}

							if (i == num[2] && j != num[1] && k == num[0]) {
								continue;
							}//num[1]���g��Ȃ��ꍇ

							if (i == num[1] && j == num[2] && k != num[0]) {
								continue;
							}

							if (i != num[0] && j == num[2] && k == num[1]) {
								continue;
							}

							if (i == num[2] && j != num[0] && k == num[1]) {
								continue;
							}//num[0]���g��Ȃ��ꍇ

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
							}//num[1]��num[0]

							if (i == num[2]) {
								if (j != num[0] && j != num[1] && k != num[0] && k != num[1]) {
									continue;
								}
							}//num[2]��num[0]

							//100�̈ʂ�Hit�ɂȂ肤��ꍇ

							if (j == num[0]) {
								if (i != num[1] && i != num[2] && k != num[1] && k != num[2]) {
									continue;
								}
							}//num[0]��num[1]

							if (j == num[2]) {
								if (i != num[0] && i != num[1] && k != num[0] && k != num[1]) {
									continue;
								}
							}//num[2]��num[1]

							//10�̈ʂ�Hit�ɂȂ肤��ꍇ

							if (k == num[0]) {
								if (i != num[1] && i != num[2] && j != num[1] && j != num[2]) {
									continue;
								}
							}//num[0]��num[2]

							if (k == num[1]) {
								if (i != num[0] && i != num[2] && j != num[0] && j != num[2]) {
									continue;
								}
							}//num[1]��num[2]

							//1�̈ʂ�Hit�ɂȂ肤��ꍇ

							opt[i][j][k] = 'f';

						}
					}
				}
			}
		}


		printf("\n�ȉ����l����ꂤ�鐔�ł�\n\n");

		int count30 = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

					if (opt[i][j][k] == 't') {

						int output = i * 100 + j * 10 + k;
						printf("%03d ", output);
						//opt�̒l��t�ł�����̂�S�ďo��

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

		//printf("CPU���ԁF %d\n", cpu_time);

		count++;

	} while (count < 100);
	//��͉񐔂�100��ɒB������v���O�������I������

	system("pause");

	return 0;
}