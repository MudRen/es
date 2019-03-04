#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(19);
        set_name( "General Lee", "����ڶ�ʹ ���" );
        add ("id", ({ "general", "lee", }) );
        set_short( "����ڶ�ʹ ���" );
        set_long( @C_LONG
����ؽڶ�ʹ������ǵ���������ĳ�購��Ů��������ȹ����ϵ��ƽ�����ƣ���
���Ѿ������ڶ�ʹ��ְλ�ˡ���������˵���������ֵ��׼��ӵܣ���\����ܻ����
C_LONG
        );
    set( "alignment", 0 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
    set_perm_stat( "dex", 29 );
    set_perm_stat( "str", 20 );
    set_perm_stat( "int", 15 );
    set_perm_stat( "con", 15 );
    set_perm_stat( "karma", 25 );
    set ("max_hp", 800);
    set ("hit_points", 800);
    set ("wealth", ([ "gold": 400 ]) );
    set_natural_weapon( 35, 10, 17 );
    set_natural_armor( 52, 33 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":55, "weakest":35, "ganglion":85,"vascular":65]));
    set ("special_defense", ([ "all":60 ]) );
    set ("weight", 400);
    set ("exp_reward",30500 );
    set_experience(1000000);
    set_skill("longblade",100);
    set_skill("parry",100);
    set_skill("concentrate",100);
    set("c_death_msg","%s �����в��ʵ�˵��������...���ǲ��Ƿ�����̴�...����Ȼ��͹���...\n");
    set( "inquiry", ([
         "plates" : ({ "��Ҫ�Ҷ��ҵ��ղ�Ʒ�...���������пգ����԰��Ҳ�(polish)һ�¡�\n" }),
         "mirror" : ({ "�..�����ƾ��Ӱ�..�ϴ�һ�����ֱ��ŵĴ������������Ŷ�����\n"
                     "������Ҳ���Ǻ�ϲ�����澵�ӣ����˾����˰�..�����Ҫ����Ƭ��Ӧ������������ɡ�\n" }),
         "button" : ({ "��..����ϲ�������Ǽ����µ���һ�Ž����..��������ҵ���\n"
                    "���㻹���ң��һ��������..\n" })
           ]) );
 
    wield_weapon(OBJS"king_sword");
    equip_armor(OBJS"gloves01");
    equip_armor(OBJS"cloth01");
    equip_armor(OBJS"amulet01");
}
 
int accept_item(object me,object item)
{
    string name;
    name=(string)item->query("name");
     if ( !name || (name!="golden button") ) return 1;
     else {
     tell_object(me,
@MISSION
�����������ÿ޵ض���˵����лл������һ��������......����
����˵����Ϊ�˴�л���Ķ��飬�ҵ��ղ��ҿ���������ȥ�ι� ����
MISSION
        );
                item->remove();
        this_player()->set_temp("give_button",1);
        return 1;
        }
}
 
void die()
{
 // ��������....
   int i ;
   object *sword,*tmp, empire_sword;
 
   tmp = children("/d/eastland/mumar/objs/king_sword");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
    {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
 
 // �ĳ�clone ������ sword ��춶��� remove
 
   if( sizeof(sword)>1 ){
     empire_sword = present( "empire sword", this_object() );
     tell_room(environment(this_object()),
  " ���������˵���潣�Ѿ�����.....��ѷ���Ʒ���ܸ����˿�����\n\n���Ӳ�ǰѽ�������ȥ.....�㿴��Ŀ�ɿڴ�...\n\n",this_object() );
   empire_sword->remove();
   }
 ::die();
 }
