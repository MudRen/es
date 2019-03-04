#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short( "������԰" );
	set_long(
@LONG
������������԰��������ȥ����ν�����滨��ݼ�춴˵أ�һ���ļ�����԰
���أ�õ�塢�������������ӡ��β��ˮ�ɡ������㣮������������������
һƬ����ǧ�죬ƽʱ������Ů������ϲ����������̸�졣
LONG
	);
	set( "exits", ([
	     "west" : OTEMP"palace5",
	]) );
        set("search_desc", ([
            "here":"@@to_search_here",
            ]) );
         set("item_desc",([
             "rose":"@@look_rose",
             ]) );
         set("light",1);
         reset(); 
}

string to_search_here()
{
   string str;

   str="����ãã����֮�У�����һ����õ��(rose)��\n";
   this_player()->set_temp("rose/check",1);
   return str;
}

string look_rose()
{
  if (this_player()->query_temp("rose/check"))
    return "һ��������ɫ��â��õ�廨��\n";
  return 0;
}

void init()
{
  add_action("do_get","get");
}

int do_get(string arg)
{
  object ob;

  if (!arg || arg!="rose" || !this_player()->query_temp("rose/check") )  {
//    write("��Ҫ��ɶ?\n");
//    return 1;
      return 0;
  }
  
  if (!this_player()->query_quest_level("Dragon_box")) {
    write("������ȥժ���õ�廨��ȴ�̸��գ�ԭ���㿴����ֻ�ǻ�Ӱ��\n");
    return 1;
  }

  if (present("rose",this_player())) {
    write("��Ϊʲ�᲻��������Ҳ�ܹ�������ѵ�һ������õ����?\n");
    return 1;
  }

  if (be_get) {
    write("���õ���Ѿ�����ժ���ˡ�\n");
    return 1;
  }

  write ("������İ������ɫõ�廨ժ��������\n");
  ob=new(OOBJ"rose");
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
