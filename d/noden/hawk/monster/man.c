inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "hawkman man", "������׳��" );
        add("id",({"man","hawkman"}) );
        set_short( "������׳��" );
        set_long(
                "����ǿ׳������׳����������ΪĳЩԵ������û�н��ܾ���ѵ��.\n"
        );
        set( "gender", "male" );
        set( "race", "hawkman" );
        set( "alignment", 300 );
        set( "time_to_heal", 15 );
        set_natural_armor( 13, 7 );
        set_natural_weapon( 13 , 15 , 7 );
        set_perm_stat( "dex", 6 );
        set( "wealth/silver", 90 );
}

