inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Servant","仆人" );
        add("id",({"servant"}) );
        set_short( "仆人" );
        set_long(@LONG
雷多家的仆人，身上穿的破破烂烂，不过工作的满认真的，颇得雷多的喜爱。
LONG
        );
        set( "alignment", 200 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance",12);
        set("chat_output",({"仆人自言自语: 雷多大人的酒呢...?\n"}));
        set( "wealth/silver", 300 );
}
