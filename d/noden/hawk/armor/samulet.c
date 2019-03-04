inherit ARMOR;

void create()
{
        set_name("sky amulet","天空守护徽章");
        add("id",({"amulet","sky amulet"}) );
        set_long(@LONG
这是天空之城自古相传的徽章，由天空之城所独有的奇里斯金属
所打造，外加上天界神圣的力量加诸其上，传说里谁要是能得到这枚
守护徽章，就能和大地融为一体，得到无穷无尽的力量。不过老一辈
的鸟人都说，把这枚徽章放到吸收过神圣太阳光芒的三角锥里，在祭
坛神圣力的催化之下，可以释放出徽章蕴含的能量。
LONG
        );
        set_short( "sky amulet","天空守护徽章");
        set( "no_sale",1);
        set( "unit", "枚" );
        set( "weight", 10 );
        set( "type", "misc" );
        set( "armor_class", 0 );
        set("material","light_metal");
        set( "defense_bonus", 6 ); //hope can higher ....
        set( "value", ({ 1290, "silver" }) );
}
