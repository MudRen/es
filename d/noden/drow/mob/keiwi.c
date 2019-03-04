
#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(17);
        set_name( "Adventurer Keiwi","ð�ռ���ά" );
        add ("id", ({ "adventurer","keiwi" }) );
        set_short( "Adventurer Keiwi","ð�ռ���ά" );
        set("unit","λ");
        set("alignment",740);
        set("weight",900);
        set("wealth/copper",3800);
        set_long(
@C_LONG
����һλ���������ð�ռң�������ḻ������������Ͽ����ϵ���
�ε��ڰ������ʱ������������Ϊ�򵼵ġ�����������ƺ���Ϊ����
(lover) ʧ�ٶ����ա�
C_LONG
        );
        set_perm_stat("int", 16);
        set_perm_stat("str",23);
        set("max_hp",650);
        set("hit_points",650);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1", 13);
        set ("natural_max_damage1", 22);
        set ("natural_armor_class", 78);
   set( "special_defense", ([
       "all":20, "none":12]));
        set ("race", "human");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",75);
        set_skill("parry",65);
        set( "inquiry", ([
             "snake" : ({"�����Ĵ���...�����������������ȥ��� ..\n"}),
             "herb" : ({
                      "�....���Ѳ�Ŷ...�������У�����ֻ��һ�������ܸ���..\n"
                      "���������һ��æ���Ҿ͸������Ѳ�....\n"
                       }),
             "help" : ({
       "��������𣿺ã����ڴ˵�̽���Ѿ���������\n"
       "����������ҵ��͵�������..�����...\n"
       "��������Ѱ˾�ȿ��������ܣ���������Ҫһյ�͵ƣ����ܸ���һյ��\n"
                       }),
             "lover" : ({
                       "���ˣ����ȵȰ�....������С��û��Ϊ�ҽ��ܣ��ٵ�һ���Ӱ�\n"
                        })
                   ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"ring1");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="lamp"))
     return 1;
write("��ά˵��̫���ˣ���Ү�����ֿ��Լ����ҵ�ð���ˡ�\n");
   if (!this_object()->query("gress")) {
     write("��ά����һ�����Ѳݡ�\n");
     ob=new(OBJ"gress");
     ob->move(this_player());
     set("gress",1);
   }
   else
     write("��ά˵����������������ˣ����reboot��...������\n");
   return 1;
}
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE
��ά�ߺ�һ�����벻������������һ�����������������.....

�㿴����ά�ı����е�����һ�����ס�

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_plate");
    obj->move(this_object());
   ::die(1);
   }

