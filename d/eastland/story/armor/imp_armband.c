inherit ARMOR;
void create()
{
     set_name( "fighter's armband","սʿ���ۻ�" );
     add( "id",({ "armband" }) );
     set_short( "սʿ���ۻ�" );
     set_long(@C_LONG
һ˫�ɡ������������  �������Ȼ��ʯ�Ƴɵıۻ��������ټ��Է��׵����
ͬʱ�ڱۻ��ڲ໹�з���˿�ʲ��ϣ����������ǳ����ʡ�
C_LONG
     );
     set( "unit","˫" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
        (["energy":-20,"electric":20]) );
}