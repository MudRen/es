inherit ARMOR;
void create()
{
     set_name( "fighter's leggings","սʿ���ּ�" );
     add( "id",({ "leggings" }) );
     set_short( "սʿ���ּ�" );
     set_long(@C_LONG
һ���ɡ������������  �������Ȼ��ʯ���ƶ��ɵ��ּף������ټ��Է��׵���
�ͬʱ���ڲ����˿�ʲ��ϣ����������ǳ����ʡ�
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "legs" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",3 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
         (["electric":5]) );
}