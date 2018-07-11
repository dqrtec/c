void	atribui_direita_v(Viagem	*viagem,	Viagem	*direita)
{
	if (viagem != NULL)
	{
		viagem->direita = direita;
	}
}

Viagem	*acessa_direita_v(Viagem	*viagem)
{
	if(viagem != NULL)
	{
		return viagem->direita;
	}
}

void	atribui_esquerda_v(Viagem	*viagem,	Viagem	*esquerda)
{
	if (viagem != NULL)
	{
		viagem->esquerda = esquerda;
	}
}

Viagem	*acessa_esquerda_v(Viagem	*viagem)
{
	if(viagem != NULL)
	{
		return viagem->esquerda;
	}
}