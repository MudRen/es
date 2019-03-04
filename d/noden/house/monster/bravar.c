// /u/m/mad/bravar.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(12);
   set_name("Bravar","���𷥶�");
   add("id", ({ "man" }));
   set_short("���𷥶�");
	set_long(
          "���𷥶�����������ŵ�����ǵľ�ҽ, ��˵����������\n"
          "������, �����˵ص��顣Ϊ�������ᱻ�������ؽ�?\n"
	);
   set("race","human");
   set("gender","male");
   set("alignment",700);
   set("unit","λ");
   set_perm_stat("dex",16);
   set_perm_stat("int",16);
   set_perm_stat("pie",16);
   set_natural_armor(25,10);
   set_natural_weapon(10,6,11);
   set_skill( "blunt", 50 );
   set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 70 );
   set_temp( "aiming_loc", "ganglion" );
   set("chat_chance",10);
   set("chat_output", ({
           "���𷥶�������������: ʳ.....ʳ......\n"
           "   (��������̫С��������������...)\n"
     }) );
   wield_weapon("/d/noden/house/obj/mace");
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
   if( !name || name != "cookie" ) {
    return 0;
  }

   item->remove();
   ob = new( "/d/noden/house/obj/incantation" );
   ob->move(me);
   this_player()->set_explore("noden#26");
   tell_object( me,
     "���𷥶�˵: лл...�Һܾ�û�Զ�����! ������а�����ǻر���!\n" );
   return 1;
}
