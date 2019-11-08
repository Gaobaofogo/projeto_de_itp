
void leituraDeArquivo(char string[]) {
  FILE *arquivo = fopen(string, "r");
  char strTeste[50];

  if (arquivo == NULL) {
    printf("asdsda\n");
    return;
  }

  // Lê as linhas de um arquivo
  while (fgets(strTeste, 50, arquivo) != NULL)
    printf("%s", strTeste);

  fclose(arquivo);
}
