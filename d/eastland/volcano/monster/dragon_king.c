#include "../oldcat.h"

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dragon King of Well", "������" );
	add ("id", ({ "king", "dragon", }) );
	set_short( "������" );
	set_long(
    "  ������ԭ�Ǳ�����������Ϊ�ڶ��Ӵ������֮�ᣬ��������ۣ��ű��ᵽ���䣬\n"
    "����ʵ�Ǻ����ǻ۵��ˣ������������������ޡ�����ʶ��ͳ�������Բ�ͬ���졣\n"
	);

        set( "alignment",1600);
        set( "gender", "male" );
        set( "race", "dragon" );
        set( "unit", "λ" );
        set( "likefish",1);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 20);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
	set("special_defense", (["all":60,"none":60,"monk":60,"scholar":60]) );
        set ("aim_difficulty", ([ "critical":30, "vascular":30, "weakest":30, "ganglion":30 ]) );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
        set ("max_sp", 2000);
        set ("spell_points",2000);
	set ("wealth", ([ "gold": 500 ]) );
	set_natural_weapon( 5, 5, 10 );
	set_natural_armor( 50, 41 );
        set ("weight", 400);
        set( "inquiry", ([
             "rose" : "@@ask_rose" ,
             "princess" : "@@ask_princess" ,
             "daughter" : "@@ask_princess",
             "box" : "@@ask_box",
             "door" : "@@ask_door",
             "crystal" : "@@ask_crystal",
             ]) );
        set ("unbleeding",1);
	set ("att_chat_output", ({
	    "����˵��������ЩС�ϰ��գ��ǲ����ܻ����ҵġ�\n"
	    }) );
	wield_weapon(OWEAPON"sword1");
        equip_armor(OARMOR"legging2");
        equip_armor(OARMOR"helmet2");
        equip_armor(OARMOR"boots3");
        equip_armor(OARMOR"mail6");
}

void ask_rose( object who )
{
        tell_object( who, 
          "\n��������������õ�����ҵĻ�԰����һ�ã���������Ů����ϲ���ģ��Ҳ�����\n"
          "������������������Ⱦ��ҵ�Ů�������Ѿ�������Σ���ˡ�\n");
      return ;        
}

void ask_princess(object who)
{
      
      tell_object(who,
      "\n���������ҵ�Ů����Ϊһ�쵽�����ڻ�԰���֪��ʲ��ԭ����һ��ͻȻ����������\n"
      "��԰��Ӵ˾ͳ�˯����Ҳ\����������һ�ֵĽ����ɣ���ֻҪ�����κ�����һ��\n"
      "�����ź�ı��ꡣ\n"
     );
      return ;
}

void ask_box(object who)
{
   tell_object(who,
    "\n����������Ŀ����㣬˵�������������ʲ�� ? \n"
      "�����Һô���������Űѱ��������˻������Ҿ������������ҵı����У�Ҳ����\n"
      "���ҵĶ���֪�����������ַ���ͬ���Ĵ���\n"
   );
   return;
}

void ask_door(object who)
{
  tell_object(who,
    "\n����˵���ҵı���ֻ����ĳ��ʱ����ܽ�ȥ��\n"
  );
  return;
}

void ask_crystal(object who)
{
  tell_object(who,
    "\n����˵������ȥ����ˮ���ᷢ�����벻�����¡�\n"
  );
  return;
}

int accept_item(object me, object item)
{
   string name;
   object ob;
 
   name=(string)item->query("name");
   if (!name || (name!="living pill"))
     return 1;
   if (!item->query(me->query("name"))) {
     printf("\n����˵������ȥ����͵��ҩ�裬͵��֮������������ȡ��\n");
     item->move(me);
     return 0;
   }
   write("\n����˵���������������ҩ�������Ŀ��Ծ���Ů�����������ø��ҵ�Ů�����������£�лл��\n");
   if (!this_object()->query("key")) {
     write("����˵��������Ů�����ҵ�Կ�ס�\n");
     ob=new(OOBJ"diamond_key");
     ob->move(this_player());
     set("key",1);
   }
   else 
     write("\n����˵����Ů���޹���Կ���ѱ����������ˡ�\n");
   item->move(this_player());
   return 1;
}
void die()
{
   int i ;
   object *sword,*tmp, dragon_sword;
   
   tmp = children("/d/eastland/volcano/weapon/sword1");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
     {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
   
 // �ĳ�clone ������ sword ��춶��� remove
   
   if( sizeof(sword)>1 ){
     dragon_sword = present( "dragon sword", this_object() );  
     tell_room(environment(this_object()),
  " ����������˵������һ��ֻ��һ�Σ�����������\n�����þ�������������������飡\n",this_object() );
   dragon_sword->remove();
   }
 ::die();
}

