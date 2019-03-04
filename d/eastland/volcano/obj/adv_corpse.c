#include "../oldcat.h"

inherit "/obj/corpse";
int be_cut;

void create()
{
    ::create();
    ::set_name("advanturer","ð����");
    set_c_open_long("����ð���ߵ����壬����Ը�(cut)������ͷ��Ϊս��Ʒ��\n");
    set("weight",800);
    set("load",1000);
    be_cut=0;
}

void init()
{
  add_action("cut_head","cut");
}

int cut_head(string arg)
{
   int i;
   object wep,obj,*item;

   if (!arg || arg!="head")
      return notify_fail("��Ҫ��ɶ?\n");

   if (be_cut)
      return notify_fail(
         "���ð���ߵ�ͷ�Ѿ��������ˡ�\n");
   item=all_inventory(this_player());
   for (i=0;i<sizeof(item);i++)
     if ((string)item[i]->query("name")=="sharp knife") {
       write("���������е�����С����ð���ߵ�ͷ�ӡ����ϸ���������\n");
       obj=new(OOBJ"head");
       obj->move(this_player());
       be_cut=1;
       return 1;
     }
   write("��û���ʵ��Ĺ��߿��԰�ͷ��������\n");
   return 1;
}
