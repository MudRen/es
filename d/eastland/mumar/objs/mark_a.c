#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "army mark", "�������" );
        add( "id", ({ "army","mark" }) );
        set_short( "�������" );
        set_long( @C_LONG
����һ����Ƶ����ƣ���������������ز��������˵������Ͳ����ų���ͬ��
�ĵ�λ������(hold)������ͨ�����е�������ʿ������Ȼ��ǰ�������Ƕ���û��˽
�˶�Թ...
C_LONG
                );
                set("unit","��");
                set("weight", 10);
                set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="�ⷿ����" ) {
        tell_object(this_player(),
                "���������ƣ���������һ���ع��ؾ������ӡ�\n" );
        this_player()->set_temp("army_mark",1);
        this_player()->set_explore("eastland#26");
        } else
        tell_object(this_player(),
                "�����������񱿵�һ����ѽ��ѽ�أ�����û�����㡣\n" );
        return 1;
}