#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "nail_spirit", "nail" );
}
 
void create()
{
        set_name( "seven nail", "����׷�궤" );
        add( "id", ({ "nail" }) );
        set_short( "����׷�궤" );
        set_long( @C_LONG
����һ֧�ߴ糤�ĺ�ɫľ������ֻ����ɢ����̴���ĳ����˵������������������
��ֻľ���Ķ�ͷ����������ʮ�ַ��������㻳���ǲ�������ܶ�(nail)סЩʲ�ᡣ
C_LONG
                );
        set("unit","֧");
        set("weight", 10);
        set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
 
int nail_spirit(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="�ⷿ����" ) {
        tell_object(this_player(),
                "���������ƣ���������һ���ع��ؾ������ӡ�\n" );
        this_player()->set_temp("army_mark",1);
        } else
    if ((string)environment(this_player())->query("short")=="�ܵ�����" ) {
        tell_object(this_player(),
                "���������ƣ���������һ���ع��ؾ������ӡ�\n" );
        this_player()->set_temp("army_mark",1);
        } else
        tell_object(this_player(),
                "�����������񱿵�һ����ѽ��ѽ�أ�����û�����㡣\n" );
        return 1;
}
