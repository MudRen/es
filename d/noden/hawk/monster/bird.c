inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "Bird", "Ұ��" );
	add("id",({"Bird"}) );
   	set_short( "Ұ��" );
	set_long(
		"һֻ��ɫ��ȫ��Ư����Ұ���ƺ���æ����ʳ��.\n"
	);
	set( "alignment", 0 );
	set( "time_to_heal", 10 );
	set_natural_armor( 7, 2 );
	set_natural_weapon( 5 , 3 , 5 );
	set( "wealth/silver", 40 );
}

