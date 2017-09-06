/*Função recebe um ponteiro pra aluno e imprime todos os seus dados*/
int imprimeAluno (Aluno *a){
	if (a == NULL)
		return ();
	printf ("Nome: %s \nMatricula: %d \nCPF: %ld \nTelefone: %d \nData de Nascimento: %hd/%hd/%hd \nEndereco: %s, %s, %s, %s, %s\n", a->nome, a->mat, a->cpf, a->telefone, a->nasc.dia, a->nasc.mes, a->nasc.ano, a->end.estado, a->end.cidade, a->end.bairro, a->end.rua, a->end.comp);
	return ();
}
