inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "hawkman woman", "鸟人族妇人" );
        add("id",({"woman","hawkman"}) );
        set_short( "鸟人族妇人" );
        set_long(
                "你看到一个正为家事操劳的鸟人主妇.\n"
        );
        set( "gender", "female" );
        set( "race", "hawkman" );
        set( "alignment", 200 );
        set_natural_armor( 11, 6 );
        set_natural_weapon( 11 , 11 , 5 );
        set_perm_stat( "dex", 5 );
        set( "wealth/silver", 70 );
}

