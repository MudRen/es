inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set("id", ({ "tea" , "herb tea" }) ) ;
    set_name("herb tea","��ݲ�");
    set_short("a cup of herb tea","��ݲ�");
    set_long("The tea was made from secret prescribtion of the Otonashi's.\n",
    "������ǧ�ݼ��ܴ��䷽�Ƴɵ���ݲ衣ɶ��......˭��ǧ�ݣ�\n"
    "��......Ϊ������������룬��֪���ľͲ�Ҫ���ʰ�!!\n");
    set("tp",80);
    set("value",({ 50,"silver" }) ) ;
    set("amount",0) ;
    
}
