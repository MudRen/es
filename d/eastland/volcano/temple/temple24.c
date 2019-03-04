#include "../oldcat.h"

inherit ROOM;

int be_get;
void create()
{
	::create();
    set_short("��Ժ");
	set_long( 
@LONG_DESCRIPTION
������������Ժ���ڿ���Χǽ�ĵ�������һ�ù���������С·��ͨ����
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple14",
     "southwest":OTEMP"temple25"
     ]) );
set("pre_exit_func",([
    "east":"to_leave",
    "southwest":"to_leave",
    ]) );
set("search_desc",([
    "here":"һ��֦Ҷï�ܵĴ���(tree)������Ժ�ӵ�һ�硣\n",
    ]) );
set("item_desc", ([
    "tree":"@@look_tree",
    "fruit":"@@look_fruit",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_hit","hit");
  add_action("do_spread","spread");
}

string look_tree()
{
  if (be_get)
    return "һ��֦Ҷïʢ�Ĺ�����\n";
  return "һ��֦Ҷïʢ�Ĺ��������滹��һ�����ӣ�����ϸ���ǹ��ӣ���Ȼ�����Σ�\n�ѵ����������������ǧ���һ�ι����˲ι�(fruit)��\n";
}

string look_fruit()
{
  if (be_get)
    return "what do you want to do?\n";
  return "���������ͷ���нš������塢Ҳ���֣����紵��ʱ���ݷ��ֽŻ��ᶯ����ȥ��\n";
}

int to_leave()
{
  this_player()->delete_temp("spread_cloth");
  return 0;
}

int do_spread(string arg)
{
  if (!arg || ((arg!="cloth")&&(arg!="��"))) return 0;

  if (!(present("square cloth",this_player())))
    return 1;
  
  printf("��Ѳ�̯�������ڵ��ϡ�\n");
  this_player()->set_temp("spread_cloth",1);
  return 1; 
}

int do_hit(string arg)
{
  object ob;

  if (!arg || ((arg!="fruit")&&(arg!="����"))) return 0;
  
  if (!(present("small club",this_player()))) {
    write("�����ҡͻȻ˵���������ϡ��벻Ҫ����ֵĶ��������ҵ����壬����?\n");
    return 1;
  }
  
  if (be_get)
    return notify_fail("what do you want to do?\n");
  
  if (!this_player()->query_temp("spread_cloth")) {
    write("����С��������˲ι��������ȥ��ֻ���˲ι�һ��ؾ��굽�����ˡ�\n");
    be_get=1;
    return 1;
  }
  
  write ("����С������ˡ���������ȥ��ֻ���˲ι������������պ��������̵Ĳ��ϣ����������һ����������\n");
  ob=new(OOBJ"fruit");
  ob->set(this_player()->query("name"),1);
  ob->move(this_player());
  be_get=1;
  return 1;
}

void reset()
{
  ::reset();
  be_get=0;
}
