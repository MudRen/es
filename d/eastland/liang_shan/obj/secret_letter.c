#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("hint", "С����");
        set_short("hint", "С����");
        set_long(@CLONG
����һ�����ĺ�Ư�����ŷ⣬Ҳ������԰������������������
CLONG
        );
        set("id", ({"hint"}));
        set("unit", "��");
        set( "weight", 1 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1);
        seteuid( getuid() );
}
void init()
{
        set("owner",environment(this_object()));
        add_action( "do_open", "open");
        add_action( "do_read", "read");
}
int do_open(string str)
{

        if (!str || str != "hint" ) 
                return notify_fail(
                        "��ʲ�ᶫ����?\n");
        
        tell_object( this_player(), "���ں��񻹲��ǰѽ��Ҵ򿪵�ʱ��\n" );
        return 1;

}
int do_read(string str)
{
if (!str || str != "hint" )
                return notify_fail(
                  "��ʲ��?\n");
                                        
                 tell_object( this_player(), "��Ӧ���ȴ򿪽���...\n" );
                 return 1;
}

