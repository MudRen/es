#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "scale blade","���۳���");
        add( "id",({ "blade" }) );
        set_short( "���۳���");
        set_long(
@CLONG
������������һ�Ѻ�ɫ�޹���ĳ�������˵��������ǰ����ΰ�����������
        ������������֮�أ���˾�ȿ�Ů��ս���أ����Ů�����������
���������Ǵﲻ�ж�����ܣ�������ð�ռ���ά�ڽ���֮��̽��ʱ��������
��������һ�����ף���˵�������Ǵ������µģ���������಻֪���Ĵ���Ƭ
�������������ķ������Щ��Ƭ�������ѽ�������ȫ�Ǵ���Ƭ����ɣ���
�����������൱���˺�����

CLONG
                );
        set( "unit", "��" );
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 25 );
        set( "max_damage", 38 );
        set( "nosecond", 1 );
        set( "bleeding", 16);        
        set( "weight", 140 );
        set( "value", ({ 1700, "silver" }) );
}
// WC, damage, bleeding is ok, suggest that:
// add some limit for 66 longblade(confused players*grin*)
// QCing.

int stop_wield(object owner)
{
   int lbskill;

   lbskill = (int)owner->query_skill("longblade");

   if( lbskill> 65 ) return 0;
      write( "���޷�װ����һ������\n" );
   return 1;
}
