#include "include/data/image.h"
#include "include/io/bmp.h"
#include "memory"
#include "include/utils/args_processor.h"
#include "include/pipeline.h"
#include "iostream"


int main(int argc, char **argv) {
    try {
        ArgsProcessor args_processor(argc, argv);

        std::unique_ptr<ImageFormat> bmp = std::make_unique<BMP>();

        Image image = bmp->Load(args_processor.GetInputFile());

        Pipeline pipeline{args_processor.GetFilters()};

        image = pipeline.ProcessAll(image);

        bmp->Save(image, args_processor.GetOutputFile());

        return 0;
    } catch (const std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    }
}