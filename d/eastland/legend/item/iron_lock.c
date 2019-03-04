#include <mudlib.h>

inherit OBJECT;

void create()
{
     set_name("iron lock", "������");
     add("id", ({ "lock"}) );
     set_short("������");
     set_long(@C_LONG
һ�����ص�������
C_LONG
     );                             
     set( "unit", "��" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_lock","iron_lock");
}
int do_lock(string arg)
{
    object holder,env,victim;
   
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !victim=present("beast",env) ) {
       tell_object(holder,"�Բ���,�벻Ҫ������\n");
       return 1;
    }
    if ( !victim->query("npc") ) {
       tell_object(holder,"��,�������г���?\n");
       return 1;
    }
    if ( !victim->query("faint") ) {
       tell_object(holder,"��,������������\n");
       return 1;
    }
    if ( victim->query("locked") ) {
       tell_object(holder,"���������Ѿ���������!\n");
    }
    tell_object(holder, sprintf("���ô���������%s�ľ�����,�ǿ����ָ������˽���!\n",
       victim->query("c_name")) );
    tell_room(env,sprintf(
       "%s�ô���������%s�ľ�����,�ǿ����ָ������˽���!\n",holder->query("c_name"),victim->query("c_name")),holder);
    victim->set("locked",1);
    this_object()->remove();               
    return 1;
}