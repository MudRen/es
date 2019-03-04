#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Wind awl","��������׶");
    add("id", ({ "awl","wind awl" }) );
    set_short("��������׶");
    set_long(@LONG
һ���Ĵ糤�Ľ���׶���ഫ�������α������Ĵ�����ɵĶ��ű���֮һ������
����׶�����׹����������˫���������ϵ��������׶ͨ��տ����͸��˿˿��
�����ƺ���ʱ�������ַ�����ʡ�
LONG
    );
    set( "unit", "��" );
    set( "weapon_class", 30 );
    set( "type","polearm" );
    set( "min_damage", 12 );
    set( "max_damage", 23 );
    set( "weight", 70 );
    set( "wield_func","weapon_wield");
    set( "unwield_func","weapon_unwield");
    set( "value", ({ 10, "gold" }) );
    set( "bleeding",15);
    set( "second", 1 );
}

void weapon_wield()
{
  object holder;
  int my_ali,holder_level;

  holder=environment(this_object());

  if (my_ali=(int)holder->query("war_score")>20000) {
    holder_level=(int)holder->query_level();
    set("min_damage", holder_level+1);
    set("max_damage", holder_level+19);
    set("weapon_class", (int)(holder->query_perm_skill("polearm")/2)-5);
    }
}

void weapon_unwield()
{
    set("min_damage", 12);
    set("max_damage", 23);
    set("weapon_class", 30);
}
