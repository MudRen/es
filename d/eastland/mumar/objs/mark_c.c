#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "cavalry permit", "�������" );
        add( "id", ({ "cavalry","permit" }) );
        set_short( "�������" );
        set_long( @C_LONG
����һ����Ƶ����ƣ�����������������������˵�����������ų���ͬ��
�ĵ�λ������(hold)����������ʹ������ص���ƥ��
C_LONG
                );
                set("unit","��");
                set("weight", 10);
                set("value",({10, "silver"}) );
                set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "permit" ) return 0;
    if ((string)environment(this_player())->query("short")=="��" ) {
        if (this_object()->query_temp("hold_permit") ) {
             tell_object(this_player(),
                     "������˵���������Ƶ�ʱЧ�ѹ��ˡ�\n" );
             this_player()->set_temp("cavalry_mark",0);
              }
        else  {
             tell_object(this_player(),
                "���������ƣ�����ŵ�ͷ������̧һ�¡�\n" );
             this_player()->set_temp("cavalry_mark",1);
             this_object()->set_temp("hold_permit",1);
              }
        } else
        tell_object(this_player(),
                "��������������׳�һ����ѽ��ѽ�أ�����û�����㡣\n" );
        return 1;
}
