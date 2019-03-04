#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("golden basket","��ɫ����");
        add( "id" , ({ "basket" }) );
        set_short( "@@query_short");
        set_long(@C_LONG
һ�������������ӣ��е�����֮��ģ�����װ(package)���
C_LONG  );      
        set("unit","��");
        set("weight",50);
        set("basket_used",0);
        set("no_sale",1);
        set("value", ({10, "silver"}) );
}
void init()
{
    add_action("do_package","package");
}
int do_package(string arg)
{
    object player,env,dog;
    player=this_player();
    env=environment(player);
    if ( !arg || (!dog=present(arg,env)) )
       return notify_fail("����û������������\n");
    if ( query("basket_used") )
       return notify_fail("�������Ѿ�װ�˶����ˡ�\n");
    if ( !dog->query("lucky") ) 
       return notify_fail("����װ����������\n"); 
    tell_object(player,"�㸧��������ͷ��������װ�������������ͷ���룬���ǰ����黹�����˰ɡ�\n");
    dog->remove();
    set("basket_used",1);
    return 1;
}
string query_short()
{
    return sprintf("��ɫ����%s", (query("basket_used") ? " (װ���׹�����)" :
        "") );
}