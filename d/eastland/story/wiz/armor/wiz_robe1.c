inherit ARMOR;
void create()
{
     set_name( "The Archmaster's robe","����ʦ����" );
     add( "id",({ "robe" }) );
     set_short( "����ʦ����" );
     set_long(@C_LONG
һ����������ͼ����˿�����ӡ�����������ϻ����������ף�����ڰ����ﲻʱ��
��ɫ�����֡�
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",30);
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
     this_player()->add_temp("can_pass_spell",1 );
     return 1;
}
int unequip_cloth()
{
     this_player()->add_temp("can_pass_spell",-1);
     return 1;
}