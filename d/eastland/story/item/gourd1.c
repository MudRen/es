#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("red gourd","����«");
        add("id",({"gourd"}));
        set_short( "@@query_short");
        set_long("@@query_long");
        set("unit","��");
        set("weight",10);
        set("no_sale",1);
        set("value", ({100, "silver"}) );
}
string query_short()
{
   return sprintf("����«%s", (query("heaven_water") ? " (װ������֮ˮ)" : "") );
}
string query_long()
{
   return sprintf("һ����ɫ�Ĵ��«��%s", (query("heaven_water") ? "���԰��������Һ������(full)��\n":"��������������(fill)�á�\n"));
}
void init()
{
   add_action("do_full","full");
   add_action("do_fill","fill");
}
int do_full(string arg)
{
   object player,flute;
   if ( !query("heaven_water") ) 
      return notify_fail("��«��û���κ���Һ��\n");
   if ( !arg ) return notify_fail("Syntax:<full items>��\n");
   player=this_player();
   if ( !(flute=present(arg,player)) )
      return notify_fail("��û������������\n");
   if ( flute->query("name") != "fly flute" )
      return notify_fail("�㲻�ܰѺ�«��ġ�����֮ˮ������������ȥ��\n");
   if ( flute->query("left_times") )
      return notify_fail("�Ƕ��������Ѿ�������������֮ˮ���ˡ�\n");
   write("�㻺���ذѺ�«��ġ�����֮ˮ������������֮�ѡ��ڡ�\n");
   flute->set("flute_left",1);
   remove();        
   return 1;
}
int do_fill(string arg)
{
   object env;
   if( !arg || arg!="gourd" )
      return notify_fail("Syntax:<fill gourd>��\n");
   if( query("heaven_water") )
      return notify_fail("��«���Ѿ�װ����Һ�ˡ�\n");
   env=environment(this_object());
   if( living(env) ) env = environment(env);
   if( !env->query("heaven_water") )
      return notify_fail("�����«��������װ������κ���Һ��\n");
   set("heaven_water",1);
   write("\n\n��Ȼ�Ӻ�«�ڲ���һ���������������������ȥ��˲�䣬��������ʥˮ��������֮ˮ����\n\n\n");
   return 1;    
}