struct Usuario
{
	int	 id;
	char nome[80];
	Usuario	**amigos;
	Viagem	*viagens;
};

Usuario* novo_u(int	id,	char* nome)
{
	if (id>0 && strlen(nome)>0)
	{
		Usuario user = (Usuario*)malloc(tamanho_u());
		
		if (user==NULL)
		{
			return NULL;
		}
		else
		{
			user->id = id;
			strcpy(user->nome,nome);
			user->amigos
		}

		return user;


	}

}