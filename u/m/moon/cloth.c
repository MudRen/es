
inherit ARMOR;

void create()
{
        set_name("cloth","�ֲ���");
       add("id",({"cloth","clothing"}) );
        set_short("a clothing","����");
	set_long(
         "This plate seems heavy and enhanced with holy power.\n",
          "����һ������ͨ�Ĳ���\n"
	         );
	set( "unit", "��" );
        set("weight",10);
	set( "type", "body" );
       set("material", "cloth");
set("armor_class",40);
set("defense_bonus",10);
set("special_defense",(["fire":50, "colde":50, "divine":50, "evil":50, "magic":50]));
      set("value",({0,"silver"}));
}
