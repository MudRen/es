inherit ARMOR;
void create()
{
     set_name( "captain's cloth","����Խ�����" );
     add( "id",({ "cloth" }) );
     set_short( "����Խ�����" );
     set_long(@C_LONG
���޲��Ƴɵ�һ���ں�ɫ���ۣ����������ǳ����ᣬ�ʺ���Щ�ж����ݵ���������
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
     set("special_defense",
        (["evil":-20]) );
}
