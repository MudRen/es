inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Servant","����" );
        add("id",({"servant"}) );
        set_short( "����" );
        set_long(@LONG
�׶�ҵ����ˣ����ϴ����������ã�����������������ģ��ĵ��׶��ϲ����
LONG
        );
        set( "alignment", 200 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance",12);
        set("chat_output",({"������������: �׶���˵ľ���...?\n"}));
        set( "wealth/silver", 300 );
}
