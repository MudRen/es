inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "hawkman girl", "������СŮ��" );
	add("id",({"girl","hawkman"}) );
   	set_short( "������СŮ��" );
	set_long(
		"���������������СŮ���������Աߵ�С�к�������.\n"
	);
	set( "gender", "female" );
	set( "race", "hawkman" );
	set( "alignment", 370 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 15 );
	set( "wealth/silver", 60 );
}

