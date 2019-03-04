#include "../moyada.h"

inherit OBJECT;

void create()
{
        set_name( "Mirror of True", "��֮��" );
        add( "id", ({ "mirror" ,}) );
        set_short("��֮��");
        set_long(@CLONG
һ�����������ľ��ӣ���˵��ӳ��һ���˵�����Ŀ��
�����������(show)������ʶ������αװ��
CLONG
        );
        set("weight", 15 );
        set("no_sale",1);
        set("value", ({ 200 , "silver" }) );
        set("unit", "��");
}           

void init()
{
    add_action( "to_show", "show");
}

int to_show( string msg )
{
    string who;
    object ob;
    if( !msg ) return 0;
    if( sscanf( msg, "mirror to %s", who )!=1 ) 
      return notify_fail("Show what to whom ??\n");
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(), "����û����ˡ�\n");
      return 1;
    }
    if( undefinedp(ob->change(ob, this_player())) )
      tell_object( this_player(), 
        ob->query("c_name")+"˵: ���ʲ��?\n" );
    return 1;
}
