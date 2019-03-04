#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("platinum tiger finger", "�׽�ָ��");
        add( "id", ({ "ring","finger" }) );
        set_short( "�׽�ָ��" );
        set_long(
@C_LONG
����һֻ�������ص�װ��Ʒ�������İ׽��ƹ��������ס�����ָ
������д�˺ܶ���ֵķ��ţ��ڿ���ĵط��������һ��СС����
������Դ�������
C_LONG
        );
        set( "unit", "��");
        set( "type", "finger" );
        set( "material", "heavy_metal" );
        set( "defense_bonus", 1 );
   set( "special_defense",([ "fire": 8, "cold" : -5 ]) );
        set( "weight", 20 );
        set( "value", ({ 650, "gold" }) );
        set( "no_sale", 1);
        set( "equip_func","equip_ring" );
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
        string bonus;
        bonus=this_player()->query( "knighthood" );
         switch(bonus)
         {
                case "baron":
                        set( "defense_bonus",2 );
                        return 1;
                        break;
                case "vicomte":
                        set( "defense_bonus",4 );
                        return 1;
                        break;
                case "earl":
                        set( "defense_bonus",6 );
                        return 1;
                        break;
                case "marquess":
                        set( "defense_bonus",8 );
                        return 1;
                        break;
                case "duke":
                        set( "defense_bonus",9 );
                        return 1;
                        break;
                case "lord":
                        set( "defense_bonus",10 );
                        return 1;
                        break;
                case "overlord":
                        set( "defense_bonus",10 );
                        return 1;
                        break;
         }
         return 1;
}

int unequip_ring()
{
        set( "defense_bonus",1 );
   return 1;
}
