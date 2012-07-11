# Contains unit-tests for image glue module

load    'imageglue.rb'
load    'imagewriter.rb'
load    'texturearray.rb'
require 'test/unit'
require 'FileUtils'

class ImageGlueTest < Test::Unit::TestCase
       
    def setup()
        @imageWriter = ImageWriter.new
        @imageGlue = ImageGlue.new
        @tex1 = Texture.new('test_imgs/lena.jpg')
        @tex1.load()
        @tex2 = Texture.new('test_imgs/gnu.png')
        @tex2.load()
        @tex3 = Texture.new('test_imgs/tux.png')
        @tex3.load()
        @tex4 = Texture.new('test_imgs/kde.png')
        @tex4.load()
    end
    
    def testCopy_img1()
        @tex1.textureRectangle = [30, 70, @tex1.getImage.width, @tex1.getImage.height]
        img = @tex1.getImage.dup.clear
        img.enlarge_canvas(1000, 1000)
        @imageGlue.copy(@tex1, img)
        @imageWriter.write(img, 'test_imgs/lena_shifted.jpg')
    end
    
    def testCopy_img2()
        @tex2.textureRectangle = [500, 30, @tex2.getImage.width, @tex2.getImage.height]
        img = @tex2.getImage.dup.clear
        img.enlarge_canvas(1000, 1000)
        @imageGlue.copy(@tex2, img)
        @imageWriter.write(img, 'test_imgs/gnu_shifted.jpg')
    end
    
    def testCopy_img3()
        @tex3.textureRectangle = [100, 220, @tex3.getImage.width, @tex3.getImage.height]
        img = @tex3.getImage.dup.clear
        img.enlarge_canvas(1000, 1000)
        @imageGlue.copy(@tex3, img)
        @imageWriter.write(img, 'test_imgs/tux_shifted.jpg')
    end

    def testGlue_success()
        t1 = @tex1.clone
        t2 = @tex1.clone
        t3 = @tex1.clone
        t4 = @tex1.clone
        t1.textureRectangle = [10, 10, @tex1.getImage.width, @tex1.getImage.height]
        t2.textureRectangle = [266, 10, @tex1.getImage.width, @tex1.getImage.height]
        t3.textureRectangle = [10, 266, @tex1.getImage.width, @tex1.getImage.height]
        t4.textureRectangle = [266, 266, @tex1.getImage.width, @tex1.getImage.height]
        arr = [t1, t2, t3, t4]
        img = @imageGlue.glue(1000, arr)
        @imageWriter.write(img, 'test_imgs/blit_successful.jpg')
    end

end
