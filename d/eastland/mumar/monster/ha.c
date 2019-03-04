#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        object mark;
        ::create();
        set_level(16);
        set_name( "General ha", "���� ������" );
        add ("id", ({ "general", "ha", }) );
        set_short( "���� ������" );
        set_long(
    "����ص���λ����֮һ�������������ƺ���һ�ź�ɫ�����������֡�\n"
    "��������������ز�������ָ�ӣ���������ʿ���������ĵ��Ⱥ���ǲ��\n");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "int", 10 );
        set ("wealth", ([ "gold": 30 ]) );
        set_natural_weapon(10,10,20);
        set_natural_armor(72,35);
    set ("weight", 300);
    set ("aim_difficulty",([ "critical":30,"vascular":25]) );
    set ("chat_chance", 5);
    set("chat_output",({
        "���������㡸������һ����\n",
        "��������Ȼ�����Ƿ��������˵����������������\n",
        "������ȫ������ɢ������������Ц�ؿ����㡣\n"
        }));
    set_skill("longblade",90);
    set_skill("parry",80);
    set("special_defense",(["all":20,"none":5]));
    set("tactic_func","fire_tactic");
    wield_weapon(OBJS"shadow_sword");
    equip_armor(OBJS"cloak01");
    equip_armor(OBJS"shield01");
 
    mark=new(OBJS"mark_a");
    mark->move(this_object());
}
 
int fire_tactic()
{
  object vvv;
  int dam;
 
  if ( !(vvv=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\nͻȻ��������һ���Ц��һ�����˵Ļ�������������ˡ�\n\n");
  dam=20 + random(10);
  vvv->receive_special_damage("fire",dam);
  return 1;
}
