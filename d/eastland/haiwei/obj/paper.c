#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("kill hob paper", "������");
	add( "id", ({ "paper" }) );
	set_short("������");
	set_c_open_long("�������õķ��䣬����ʹ��(use paper)ʱ�ή�������������\n");
	set( "weight", 10);;
	set( "max_load", 250);
	set( "value", ({ 0, "silver" }));
}

void init()
{
  add_action("do_use","use");
 }

int do_use(string arg)
{

//  if(arg="paper")
 
     
}