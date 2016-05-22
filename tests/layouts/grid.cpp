#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>
#include "texturemappedfont.h"
#define _INC_STDIO
#include "3rdparty/tpunit++/tpunit++.hpp"
#include "3rdparty/format/format.h"
#include "db/save.h"
#include "layouts/grid.h"
#include "sprite2d.h"
#include "renderer.h"
#include "db/dbdatabase.h"
#include "db/dbtable.h"
#include "fuzzyequal.h"
#pragma warning(pop)



/*!
 * Tests building grid via adding an objects to it
 */
struct SadGridTests : tpunit::TestFixture
{
 public:
   SadGridTests() : tpunit::TestFixture(
       TEST(SadGridTests::testSetRows),
       TEST(SadGridTests::testSetColumns),
       TEST(SadGridTests::testAddOneSpriteInOneCellTable),
       TEST(SadGridTests::testAddAndRemoveOneSpriteInOneCellTable),
       TEST(SadGridTests::testAddOneSpriteInTwoRowsTable),
       TEST(SadGridTests::testAddOneSpriteInTwoColumnsTable)
   ) {}
   // ReSharper disable once CppMemberFunctionMayBeStatic
   // ReSharper disable once CppMemberFunctionMayBeConst
   void testSetRows()
   {
       sad::layouts::Grid* grid = new sad::layouts::Grid(); 
       grid->setFixedWidth(false);
       grid->setFixedHeight(false);
       grid->setRows(1);
       grid->setColumns(1);
       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(1, 0) == NULL );

       grid->setRows(2);

       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(1, 0) != NULL );

       grid->setRows(1);

       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(1, 0) == NULL );

       delete grid;
   }
   // ReSharper disable once CppMemberFunctionMayBeStatic
   // ReSharper disable once CppMemberFunctionMayBeConst
   void testSetColumns()
   {
       sad::layouts::Grid* grid = new sad::layouts::Grid(); 
       grid->setFixedWidth(false);
       grid->setFixedHeight(false);
       grid->setRows(1);
       grid->setColumns(1);
       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(0, 1) == NULL );

       grid->setColumns(2);

       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(0, 1) != NULL );

       grid->setColumns(1);

       ASSERT_TRUE( grid->cell(0, 0) != NULL );
       ASSERT_TRUE( grid->cell(0, 1) == NULL );


       grid->setRows(4);
       grid->setColumns(5);

       grid->setColumns(3);

       ASSERT_TRUE( grid->allocatedCellCount() == 12 );

       delete grid;
   }
    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    /*! A simple basic use case: a sprite is being added to a grid with non-fixed width
        and non-fixed height table with one cell
     */
    void testAddOneSpriteInOneCellTable()
    {
        sad::Sprite2D* sprite = new sad::Sprite2D("test", sad::Rect2D(0, 0, 800, 600), sad::Rect2D(400, 400, 800, 800));
        sad::layouts::Grid* grid = new sad::layouts::Grid();
        grid->setFixedWidth(false);
        grid->setFixedHeight(false);
        grid->setRows(1);
        grid->setColumns(1);
        grid->setArea(sad::Rect2D(800, 800, 800, 800));
        sad::db::Database* db = new sad::db::Database();
        sad::db::Table* tbl = new sad::db::Table();
        sad::Renderer r;
        r.addDatabase("", db);
        db->setRenderer(&r);
        tbl->setDatabase(db);
        db->addTable("", tbl);

        sprite->setTable(tbl);
        grid->setTable(tbl);

        tbl->add(sprite);
        tbl->add(grid);

        grid->cell(0, 0)->addChild(sprite->MajorId);

        sad::Rect2D rct = grid->area();
        if (!sad::equal(rct, sad::Rect2D(800, 400, 1200, 800)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }

        rct = grid->cell(0,0)->AssignedArea;

        if (!sad::equal(rct, sad::Rect2D(800, 400, 1200, 800)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }

        rct = sprite->area();
        if (!sad::equal(rct, sad::Rect2D(800, 400, 1200, 800)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    /*! A simple basic use case: a sprite is being added to a grid with non-fixed width
        and non-fixed height table with one cell and then removed. Grid should restore it's initial zero size
     */
    void testAddAndRemoveOneSpriteInOneCellTable()
    {
        sad::Sprite2D* sprite = new sad::Sprite2D("test", sad::Rect2D(0, 0, 800, 600), sad::Rect2D(400, 400, 800, 800));
        sad::layouts::Grid* grid = new sad::layouts::Grid();
        grid->setFixedWidth(false);
        grid->setFixedHeight(false);
        grid->setRows(1);
        grid->setColumns(1);
        grid->setArea(sad::Rect2D(800, 800, 800, 800));
        sad::db::Database* db = new sad::db::Database();
        sad::db::Table* tbl = new sad::db::Table();
        sad::Renderer r;
        r.addDatabase("", db);
        db->setRenderer(&r);
        tbl->setDatabase(db);
        db->addTable("", tbl);

        sprite->setTable(tbl);
        grid->setTable(tbl);

        tbl->add(sprite);
        tbl->add(grid);

        grid->cell(0, 0)->addChild(sprite->MajorId);
        grid->cell(0,0)->removeChild(0);
        sad::Rect2D rct = grid->area();
        if (!sad::equal(rct, sad::Rect2D(800, 800, 800, 800)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }

        rct = grid->cell(0,0)->AssignedArea;

        if (!sad::equal(rct, sad::Rect2D(800, 800, 800, 800)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }
    }
    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    /*! A simple basic use case: a sprite is being added to a grid with fixed width
        and height. Grid should allow a sprite to be placed in grid and fill a cell
     */
    void testAddOneSpriteInTwoRowsTable()
    {
        sad::Sprite2D* sprite = new sad::Sprite2D("test", sad::Rect2D(0, 0, 800, 600), sad::Rect2D(400, 400, 600, 700));
        sad::layouts::Grid* grid = new sad::layouts::Grid();
        grid->setFixedWidth(true);
        grid->setFixedHeight(true);
        grid->setRows(2);
        grid->setColumns(1);
        grid->setArea(sad::Rect2D(0, 0, 200, 400));
        sad::db::Database* db = new sad::db::Database();
        sad::db::Table* tbl = new sad::db::Table();
        sad::Renderer r;
        r.addDatabase("", db);
        db->setRenderer(&r);
        tbl->setDatabase(db);
        db->addTable("", tbl);

        sprite->setTable(tbl);
        grid->setTable(tbl);

        tbl->add(sprite);
        tbl->add(grid);

        grid->cell(0, 0)->addChild(sprite->MajorId);
        sad::Rect2D rct = grid->cell(0,0)->AssignedArea;
        if (!sad::equal(rct, sad::Rect2D(0, 100, 200, 400)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }

        rct = grid->cell(1,0)->AssignedArea;
        if (!sad::equal(rct, sad::Rect2D(0, 0, 200, 100)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    /*! A simple basic use case: a sprite is being added to a grid with fixed width
        and height. Grid should allow a sprite to be placed in grid and fill a cell
     */
   void testAddOneSpriteInTwoColumnsTable()
   {
        sad::Sprite2D* sprite = new sad::Sprite2D("test", sad::Rect2D(0, 0, 800, 600), sad::Rect2D(400, 400, 700, 600));
        sad::layouts::Grid* grid = new sad::layouts::Grid();
        grid->setFixedWidth(true);
        grid->setFixedHeight(true);
        grid->setRows(1);
        grid->setColumns(2);
        grid->setArea(sad::Rect2D(0, 0, 400, 200));
        sad::db::Database* db = new sad::db::Database();
        sad::db::Table* tbl = new sad::db::Table();
        sad::Renderer r;
        r.addDatabase("", db);
        db->setRenderer(&r);
        tbl->setDatabase(db);
        db->addTable("", tbl);

        sprite->setTable(tbl);
        grid->setTable(tbl);

        tbl->add(sprite);
        tbl->add(grid);

        grid->cell(0, 0)->addChild(sprite->MajorId);
        sad::Rect2D rct = grid->cell(0,0)->AssignedArea;
        if (!sad::equal(rct, sad::Rect2D(0, 0, 300, 200)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }

        rct = grid->cell(0,1)->AssignedArea;
        if (!sad::equal(rct, sad::Rect2D(300, 0, 400, 200)))
        {
            std::cout << str(fmt::Format("Resulted in {0};{1};{2};{3}\n") << rct[0].x() << rct[0].y() << rct.width() << rct.height());
            ASSERT_TRUE( false );
        }       
   }
} _sad_grid_tests;
