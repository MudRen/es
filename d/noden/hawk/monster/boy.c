inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "hawkman boy", "������С�к�" );
	add("id",({"boy","hawkman"}) );
   	set_short( "������С�к�" );
	set_long(
		"���������������С�к�������ϵ�ë����û������.\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 320 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 10 );
	set( "wealth/silver", 20 );
}

