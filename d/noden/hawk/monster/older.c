inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "hawkman older", "����������" );
	add("id",({"older","hawkman"}) );
   	set_short( "����������" );
	set_long(
		"��̬��������������ߣ�����ң��������Ӣ�µ�����.\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 300 );
	set( "time_to_heal", 15 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 10 , 12 , 5 );
	set_perm_stat( "kar", 13 );
	set( "wealth/silver", 50 );
}

