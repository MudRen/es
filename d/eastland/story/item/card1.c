// By Player@Eastern.Stories 1996

#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit OBJECT;

string book_color();

void create()
{       
	set_name("balance_amulet","���Ʒ�" );
        add("id",({"amulet"}));
	set_short("���Ʒ�");
	set_long(@LONG
һ�Ŵ��ɫ�ķ���������ӡ������ĸ����֡��вƽ�����������Գ���ȥʹ������
��������֪������ʲ�����鷢����(use balance_amulet)��
LONG);
	set("unit","��");
}

void init()
{
        add_action("do_balance","use");
}

int fil_ppl(object obj)
{ 
  object me;
  if (wizardp(obj)) return 0;
  if (userp(obj)&& obj->query_level()>8) return 1;
  return 0;
}

void second_msg(object me,object ob)
{
  int i,j,total=0;
  string *types;
  object *here;
  mapping money;
  if ( !interactive(me)) {
    ob->remove();
  }
  tell_room(environment(me),sprintf("%s%s%s%s%s%s",
    set_color("\nһ��������������ϵ�Ǯ�Ҷ�������....\n","HIB"),
    set_color("�׽��    ","HIW"),set_color("���    ","HIY"),
    set_color("����    ","CYAN"),set_color("ͭ��    ","YEL"),
    set_color("������裬Ȼ���ȫ����ʧ������...........\n\n","HIB"))
    );
  here = filter_array(all_inventory(environment(me)),"fil_ppl",this_object());
  for(i=0;i<sizeof(here);i++) {
    money = here[i]->query("wealth");
    if( !money ) money = ([]);
    types = keys(money);
    for( j=0; j<sizeof(types); j++ )
      total += money[types[j]] * coinvalue( types[j] );
  }
  total = (total / (sizeof(here)))/10;
  for(i=0;i<sizeof(here);i++) {
    here[i]->delete("wealth");
    here[i]->set("wealth/silver",total);
  }  
  me->delete_temp("block_command");
  ob->remove();
}

int do_balance(string arg)
{
  object ob;
  
  if (!arg||arg!="balance_amulet")
    return 0;
  if (!(ob=present(arg,this_player())))
    return 0;
  if (this_player()->query_level() < 9 ) {
    tell_object(this_player(),"����Ϊ����������޷�ʹ��������Ʒ��\n");
    return 1;
  }
    
  tell_object(this_player(),set_color(
    "\n������ذѷ���˺�˿�����ֻ��������ƴ�ӵ����������ס�����ÿһ����..\n\n","HIY")
    );
      
  tell_room(environment(this_player()),set_color(sprintf(
    "\n%s������ذѷ���˺�˿�����ֻ��������ƴ�ӵ����������ס�����ÿһ����..\n\n",
    this_player()->query("c_name")),"HIY"),this_player());
  this_player()->set_temp("block_command",1);     
  call_out("second_msg",3,this_player(),ob);
  return 1;
}

