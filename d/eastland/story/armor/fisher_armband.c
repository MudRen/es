inherit ARMOR;
void create()
{
     set_name( "lock armband","�һ���" );
     add( "id",({ "armband" }) );
     set_short( "�һ���" );
     set_long(@C_LONG
�һ���ԭ��������ס��Щ���񼫵��ˣ�һ�������ϣ���������֮����Զ������
�ƣ�����ȫ�����ܻ���һ���ʹ����
C_LONG
     );
     set( "unit","˫" );
     set( "weight",100 );
     set( "type","arms" );
     set( "material","heavy_metal" );
     set( "armor_class",3 );
     set( "defense_bonus",3 );
     set( "value",({ 2320,"silver" }) );
     set( "equip_func","equip_ring");
     set( "unequip_func","unequip_ring" );
}
void init()
{
    add_action("do_remove","remove");
}
int do_remove(string arg)
{
    object player,armband;
    player=this_player();
    if ( (!armband=present(arg,player)) || 
         (!armband->query("equipped"))||(armband!=this_object()) )
    return 0;     
    if ( player->query("alignment") > 0 )
    return 0;
    write("\n�һ���������ס���˫�֣������޷����ѣ�\n\n");
    return 1;
}
int equip_ring()
{
     if ( this_player()->query("alignment") > 0 ) return 1;
     write("\n\n�һ�����Ȼ�����̿һ�㣬��ʹ�����˫�֣�\n\n\n\n");
     this_player()->add("hit_points",-100);
     set("armor_class",1);
     set("defense_bonus",1);
     return 1;    
}
int unequip_ring()
{
     set("armor_class",3);
     set("defense_bonus",3);
     return 1;
}